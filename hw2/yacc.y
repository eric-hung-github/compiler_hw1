%{
#define Trace(t)        printf(t)
#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;
SymbolTableStack symbolTableStack =  SymbolTableStack();

// a=a+b segmentation fault
// (expression) 

int yylex();


void yyerror(string s)
{
    cout<<"Error : " << s <<endl;
    exit(-1);
}

int symbolTableSize = -1;
int returnType;
int local_base = 0;
int label_no = 0;
vector<Value* > arguments;
bool programIsDeclare = false;
bool blockIsDeclare =false;
%}

%union
{
    int type;
    int int_value;
    float float_value;
    bool bool_value;
    string* str_value;
    Value* value;
    Symbol* symbol;
}
%token <str_value> ID
%token <str_value> C_STR
%token <int_value> C_INT
%token <bool_value> TRUE FALSE
%token <float_value> C_FLOAT

/* token */
%token SEMICOLON

%token COMMA FAN MO ARROW DOT

%token LB RB LCB RCB LSB RSB

%token ADD SUB MUL DIV MOD

%token BT ST SET BET EQL NEQ

%token AND OR NOT

%token ASIGN ADDASIGN SUBASIGN MULASIGN DIVASIGN
 
%token BOOL BREAK CHAR CASE CLASS CONTINUE DECLARE DO ELSE EXIT FLOAT FOR FUN IF INT LOOP PRINT PRINTLN RETURN STRING VAL VAR WHILE


%left ADD SUB MUL DIV MOD
%left BT ST SET BET EQL NEQ
%left AND OR NOT

%type <type> type  
%type <value> const_expression int_expression bool_expression expression 
%type <value> components literal_constant var_name 
/* %type <value> components literal_constant var_name fun_invoc array_refer */
%start program
%%

// Program
program         : program_begin program_contents program_end
                {
                        programIsDeclare = false;
                        symbolTableStack.pop();
                        symbolTableSize--;
                };

program_begin : CLASS ID LCB
{
    programIsDeclare = true;
    symbolTableStack.push();
    symbolTableSize++;
    symbolTableStack.tableStack[symbolTableSize].name = *$2;

    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->type = ID_program;
    symbolTableStack.tableStack[symbolTableSize].insert(symbol);

};

program_end     : RCB
                ;


program_contents        : program_content program_contents
                        | program_content
                        ;


program_content         : va_declaration
                        | fun_declaration
                        | proc_declaration
                        ;

// Data Types
type    : INT
        {
                $$ = Value_int;
        }
        | FLOAT
        {
                $$ = Value_float;
        }
        | STRING
        {
                $$ = Value_string;
        }
        | BOOL
        {
                $$ = Value_boolean;
        }
        ;

// Declarations

va_declaration          : const_declaration
                        | var_declaration
                        | array_declaration
                        ;       

const_declaration       : VAL ID ASIGN const_expression
                        {
                                Symbol* symbol = new Symbol();
                                symbol->value = $4;
                                symbol->type = ID_constant;
                                symbol->name = *$2;
                                cout<<symbol->value->valueType<<endl;

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAL ID MO type ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value= $6;
                                symbol->type = ID_variable;
                                symbol->name = *$2;    

                                if(symbol->value->valueType!=$4){
                                        printf("type error");
                                        exit(-1);
                                }

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        ;

var_declaration         : VAR ID
                        {
                                Symbol* symbol = new Symbol();
                                symbol->type = ID_variable;
                                symbol->value->valueType=Value_int;
                                symbol->name = *$2;          

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAR ID MO type
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value->valueType= $4;
                                cout<<symbol->value->valueType<<endl;
                                symbol->type = ID_variable;
                                symbol->name = *$2;    

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAR ID MO type ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value= $6;
                                symbol->type = ID_variable;
                                symbol->name = *$2;    

                                if(symbol->value->valueType!=$4){
                                        printf("type error");
                                        exit(-1);
                                }

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAR ID ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->value= $4;
                                symbol->type = ID_variable;
                                symbol->name = *$2;    

                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        ;

array_declaration       : VAR ID MO type LSB num RSB
                        ;

// Function & Procedure declration
fun_declaration : FUN ID LB formal_argument_list RB MO type block
                ;

proc_declaration: FUN ID LB formal_argument_list RB block
                ;

formal_argument_list    : formal_argument COMMA formal_arguments
                        | formal_arguments
                        |
                        ;


formal_arguments        : formal_argument COMMA formal_arguments
                        | formal_argument
                        ;

formal_argument         : ID MO type
                        ;

// Statements
statement       : simple_statement
                | condition_statement
                | loop_statement
                | proc_invoc
                ;

simple_statement: ID ASIGN expression
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                cout<<"not found"<<endl;
                                exit(-1);
                        }else if (symbol->type==ID_constant)
                        {
                                cout<<symbol->name<<" is constant"<<endl;
                                exit(-1);
                        }else if (symbol->value->valueType!=$3->valueType)
                        {
                                cout<<"Type error "<<ValueTypeToString(symbol->value->valueType)<<"\t"<<ValueTypeToString($3->valueType)<<endl;
                                exit(-1);
                        }
                }
                | ID LSB int_expression RSB ASIGN expression
                | PRINT LB expression RB
                | PRINT expression 
                | PRINTLN LB expression RB
                | PRINTLN expression
                | RETURN ID
                | RETURN 
                | RETURN expression 
                ;

// Expression
const_expression        : expression
                        {
                                $$=$1;
                        }
                        ;

int_expression          : expression
                        {
                                $$=$1;
                        }
                        ;

bool_expression         : expression
                        {
                                $$=$1;
                        }
                        ;

expression      : LB expression RB
                | SUB expression
                {
                        $$=$2;
                }
                | NOT expression
                {
                        $$=$2;
                }
                | expression math_operator expression
                {
                        if($1->valueType!=$3->valueType){
                                cout<<"type error: "<<ValueTypeToString($1->valueType)<<"\t"<<ValueTypeToString($3->valueType);
                                exit(-1);
                        }
                        $$=$1;
                }
                | expression logic_operator expression
                {
                        if($1->valueType!=$3->valueType){
                                cout<<"type error: "<<ValueTypeToString($1->valueType)<<"\t"<<ValueTypeToString($3->valueType);

                                exit(-1);
                        }
                        $$=$1;
                }
                | expression bit_operator expression
                {
                        if($1->valueType!=$3->valueType){
                                cout<<"type error: "<<ValueTypeToString($1->valueType)<<"\t"<<ValueTypeToString($3->valueType);

                                exit(-1);
                        }
                        $$=$1;
                }
                | components
                {
                        $$=$1;
                }
                ;
/* 
operator        : math_operator
                | logic_operator
                | bit_operator
                ; */

math_operator   : MUL 
                | DIV
                | ADD
                | SUB
                ;

logic_operator  : BT 
                | ST
                | SET
                | BET
                | EQL
                | NEQ
                ;

bit_operator    : AND
                | OR
                | NOT
                ;

// Expression component
components      : literal_constant
                {
                        $$=$1;
                }
                | var_name
                {
                        $$=$1;
                }
                | fun_invoc
                {
                        // $$=$1;
                }
                | array_refer
                {
                        // $$=$1;
                }
                ;

literal_constant        : C_INT 
                        {
                                Value* value=new Value();
                                value->valueType = Value_int;
                                $$=value;
                        }
                        | C_FLOAT 
                        {
                                Value* value=new Value();
                                value->valueType = Value_float;
                                $$=value;
                        }
                        | C_STR 
                        {
                                Value* value=new Value();
                                value->valueType = Value_string;
                                $$=value;
                        }
                        | c_bool 
                        {
                                Value* value=new Value();
                                value->valueType = Value_boolean;
                                $$=value;
                        }
                        ;

c_bool  : TRUE
        | FALSE
        ;

var_name        : ID
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        $$ = symbol->value;
                }
                ;

array_refer     : ID LSB int_expression RSB
                ;

// Block
block   : block_begin block_contents block_end
        {
                symbolTableStack.pop();
                symbolTableSize--;
        }
        ;

block_begin     : LCB
                {
                        symbolTableStack.push();
                        symbolTableSize++;
                        symbolTableStack.tableStack[symbolTableSize].name = "block";
                }
                ;

block_end       : RCB
                ;

block_contents  : block_content block_contents
                | block_content
                |
                ;

block_content   : va_declaration
                | statement
                ;

// Conditional
condition_statement     : IF LB bool_expression RB block_or_simple_statement
                        | IF LB bool_expression RB block_or_simple_statement ELSE block_or_simple_statement
                        ;

// Loop
loop_statement  : WHILE LB bool_expression RB block_or_simple_statement
                | FOR LB ID num DOT DOT num  RB block_or_simple_statement
                ;

block_or_simple_statement       : block
                                | simple_statement
                                ;

// Invocation
fun_invoc       : ID LB comma_separated_expressions RB
                ;

proc_invoc      : ID LB comma_separated_expressions RB
                ;

comma_separated_expressions     : expression COMMA comma_separated_expressions
                                | expression
                                ;

// Num
num     : C_INT
        ;

%%

int main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );

	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
