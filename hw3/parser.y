%{
#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;
#define Trace(t)        cout<<t<<endl;

SymbolTableStack symbolTableStack =  SymbolTableStack();
fstream jasm_file;
#define jasm(t)        jasm_file<<t;


// a=a+b segmentation fault

int yylex();


void yyerror(string s)
{
    cout<<"Error : " << s <<endl;
    exit(-1);
}

%}

%union
{
    int id_type;
    int int_value;
    float float_value;
    bool bool_value;
    string* str_value;
    Value* value;
    Symbol* symbol;
    vector<Symbol*>* symbol_vector;
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

%type <id_type> type_define  
%type <value> const_expression int_expression bool_expression expression 
%type <value> components literal_constant var_refer arr_refer
/* %type <value> fun_invoc */
%start program
%%

// Program
program         : program_begin program_contents program_end
                {
                        symbolTableStack.pop();
                };

program_begin : CLASS ID LCB
{
    symbolTableStack.push(*$2);

    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->id_type = ID_PROGRAM;
    symbolTableStack.insert(symbol);

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
type_define    : INT
        {
                $$ = VALUE_INT;
        }
        | FLOAT
        {
                $$ = VALUE_FLOAT;
        }
        | STRING
        {
                $$ = VALUE_STR;
        }
        | BOOL
        {
                $$ = VALUE_BOOL;
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
                                symbol->id_type = ID_CONST;
                                symbol->name = *$2;
                                symbol->value = $4;

                                symbolTableStack.insert(symbol);
                        }
                        | VAL ID MO type_define ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *$2;    
                                symbol->value= $6;

                                if(symbol->value->value_type==$4){
                                        
                                        symbolTableStack.insert(symbol);
                                }else{
                                        yyerror("Type error");
                                }
                        }
                        ;

var_declaration         : VAR ID
                        {
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *$2;          
                                symbol->value->value_type=VALUE_INT;

                                symbolTableStack.insert(symbol);
                        }
                        | VAR ID MO type_define
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *$2;   
                                symbol->value->value_type= $4;
 
                                symbolTableStack.insert(symbol);
                        }
                        | VAR ID MO type_define ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *$2;    
                                symbol->value= $6;

                                if(symbol->value->value_type==$4){
                                        symbolTableStack.insert(symbol);
                                }else{
                                        yyerror("Type error");
                                }

                        }
                        | VAR ID ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *$2;  
                                symbol->value= $4;

                                symbolTableStack.insert(symbol);
                        }
                        ;

array_declaration       : VAR ID MO type_define LSB num RSB
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_ARR;
                                symbol->name = *$2;   
                                symbol->value->value_type= $4;
 
                                symbolTableStack.insert(symbol);
                        }
                        ;

// Function & Procedure declration
fun_declaration : FUN ID LB formal_argument_list RB MO type_define 
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *$2;   
                        symbol->value->value_type= $7;
 
                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;

                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }
                        symbolTableStack.argumentStack.clear();
                } block
                | FUN ID LB RB MO type_define block
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *$2;   
                        symbol->value->value_type= $6;
 
                        symbolTableStack.insert(symbol);
                }
                ;

proc_declaration: FUN ID LB formal_argument_list RB block
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *$2;   
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;
                        symbolTableStack.argumentStack.clear();
                }
                | FUN ID LB RB block
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *$2;   
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);
                }
                ;

formal_argument_list    : formal_argument COMMA formal_argument_list
                        | formal_argument
                        ;

formal_argument         : ID MO type_define
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_ARG;
                                symbol->name = *$1;   
                                symbol->value->value_type= $3;

                                symbolTableStack.argumentStack.push_back(symbol);
                        }
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
                                yyerror("ID not found");
                        }else if (symbol->id_type==ID_CONST)
                        {
                                yyerror("ID is const");
                        }else if (symbol->value->value_type!=$3->value_type)
                        {       
                                yyerror("Type error");
                        }
                }
                | ID LSB int_expression RSB ASIGN expression
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }else if (symbol->value->value_type!=$6->value_type)
                        {       
                                yyerror("Type error");
                        }
                }
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
                {
                        $$=$2;
                }
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
                        if($1->value_type!=$3->value_type){
                                yyerror("Type error");
                        }
                        $$=$1;
                }
                | expression logic_operator expression
                {
                        if($1->value_type!=$3->value_type){
                                yyerror("Type error");
                        }
                        $$=$1;
                }
                | expression bit_operator expression
                {
                        if($1->value_type!=$3->value_type){
                                yyerror("Type error");
                        }
                        $$=$1;
                }
                | components
                {
                        $$=$1;
                }
                ;

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

// Component
components      : literal_constant
                {
                        $$=$1;
                }
                | var_refer
                {
                        $$=$1;
                }
                | fun_invoc
                {
                        // $$=$1;
                }
                | arr_refer
                {
                        $$=$1;
                }
                ;

literal_constant        : C_INT 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_INT;
                                $$=value;
                        }
                        | C_FLOAT 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_FLOAT;
                                $$=value;
                        }
                        | C_STR 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_STR;
                                $$=value;
                        }
                        | c_bool 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                $$=value;
                        }
                        ;

c_bool  : TRUE
        | FALSE
        ;

var_refer        : ID
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }
                        $$ = symbol->value;
                }
                ;

arr_refer       : ID LSB int_expression RSB
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }
                        $$ = symbol->value;
                }
                ;

// Block
block   : block_begin block_contents block_end
        {
                symbolTableStack.pop();
        };
        ;

block_begin     : LCB
                {
                        symbolTableStack.push("block");
                }
                ;

block_end       : RCB
                ;

block_contents  : block_content block_contents
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

        string jasm_target_path = argv[1];
        jasm_target_path += ".jasm";
        jasm_file.open(jasm_target_path, ios::out | ios::trunc);
        /* if(yyparse() == 1){
        yyerror("parsing error");
                
        } */

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
