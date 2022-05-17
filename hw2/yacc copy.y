%{
#define Trace(t) if (Opt_P) printf(t)
int Opt_P = 1;

#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;
SymbolTableStack symbolTableStack =  SymbolTableStack();


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
// vector<Value* > arguments;
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
    /* Value* value; */
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

%type <type> type const_expression int_expression bool_expression expression 
%type <type> components literal_constant var_name array_refer
%type <type> fun_invoc proc_invoc


/* left */
%left AND OR NOT
%left BT ST SET BET EQL NEQ
%left ADD SUB MUL DIV 

%start program
%%

// Data Types
type    : INT
        {
                $$ = Value_int;
        }
        | FLOAT 
        {
                $$ = Value_float;
        }
        | BOOL 
        {
                $$ = Value_boolean;
        }
        | STRING 
        {
                $$ = Value_string;
        }
        ;

// Declarations
glob_declaration        : declaration
                        ;

local_declaration       : declaration
                        ;

declaration     : const_declaration
                | var_declaration
                | array_declaration
                ;
// Const & Var
const_declaration       : VAL ID ASIGN const_expression
                        {
                        Symbol* symbol = new Symbol();
                        symbol->value = $4;
                        symbol->type = ID_constant;
                        symbol->name = *$2;        
                        symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAL ID type ASIGN const_expression
                        {
                        if($5 == $3){
                                Symbol* symbol = new Symbol();
                                symbol->value = $5;
                                symbol->type = ID_constant;
                                symbol->name = *$2;        
                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        };

var_declaration         : VAR ID
                        {
                        Symbol* symbol = new Symbol();
                        symbol->type = ID_variable;
                        symbol->name = *$2;        
                        symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAR ID MO type
                        {
                        Symbol* symbol = new Symbol();
                        symbol->type = ID_variable;
                        symbol->value = $4;
                        symbol->name = *$2;        
                        symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        | VAR ID MO type ASIGN const_expression
                        {
                        if($4 == $6){
                                Symbol* symbol = new Symbol();
                                symbol->type = ID_variable;
                                symbol->value = $6;
                                symbol->name = *$2;        
                                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        }
                        | VAR ID ASIGN const_expression
                        {
                        Symbol* symbol = new Symbol();
                        symbol->type = ID_variable;
                        symbol->value = $4;
                        symbol->name = *$2;        
                        symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        ;

array_declaration       : VAR ID MO type LSB num RSB
                        {
                        Symbol* symbol = new Symbol();
                        symbol->value = $4;
                        symbol->type = ID_array;
                        symbol->name = *$2;        
                        symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                        }
                        ;

// Program
program         : program_begin program_content program_end
                ;

program_begin : CLASS ID LCB
                {
                symbolTableStack.push();
                symbolTableSize++;
                symbolTableStack.tableStack[symbolTableSize].name = *$2;

                Symbol* symbol = new Symbol();
                symbol->name = *$2;
                symbol->type = ID_program;
                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                };

program_end : RCB
                {
                symbolTableStack.pop();
                symbolTableSize--;
                };

program_content : declarations
                ;

// Declaration
declarations    : declarations declarations
                | glob_declaration
                | fun_declaration
                | proc_declaration
                ;

// Function & Procedure declration
fun_declaration : FUN ID LB formal_arguments RB MO type block
                {
                Symbol *symbol = new Symbol();
                symbol->name = *$2;
                symbol->type = ID_function;
                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                }
                ;

proc_declaration: FUN ID LB formal_arguments RB block
                {
                Symbol *symbol = new Symbol();
                symbol->name = *$2;
                symbol->type = ID_procedure;
                symbolTableStack.tableStack[symbolTableSize].insert(symbol);
                }
                ;

formal_arguments        : formal_arguments COMMA formal_arguments
                        | ID MO type
                        |
                        ;

// Statements
statements      : statements statements
                | simple_statement
                | condition_statement
                | loop_statement
                | proc_invoc
                ;

simple_statement: ID ASIGN expression
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        if(id->type!=ID_variable ||id->value!=$3){
                                exit(-1);
                        }
                }
                | ID LSB int_expression RSB ASIGN expression
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        if(id->type!=ID_array ||id->value!=$3){
                                exit(-1);
                        }
                }
                | PRINT LB expression RB
                | PRINTLN LB expression RB
                | RETURN ID
                | RETURN 
                | RETURN expression 
                ;

// Expression
const_expression        : expression
                        {
                                $$ = $1;
                        }
                        ;

int_expression          : expression
                        {
                                $$ = Value_int;
                        }
                        ;

bool_expression         : expression
                        {
                                $$ = Value_boolean;
                        }
                        ;

expression      : SUB expression
                {
                        $$=$2;
                }
                | expression math_operator expression
                {
                        $$=$1;
                }
                | expression logic_operator expression
                {
                        $$=$1;
                }
                | expression bit_operator expression
                {
                        $$=$1;
                }
                | components
                {
                        $$=$1;
                }
                ;

math_operator   : MUL DIV ADD SUB
                ;

logic_operator  : BT ST SET BET EQL NEQ
                ;

bit_operator    : AND OR NOT
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
                        $$=$1;
                }
                | array_refer
                {
                        $$=$1;
                }
                ;
       
literal_constant        : C_INT 
                        {
                                $$ = Value_int;
                        }
                        | C_FLOAT
                        {
                                $$ = Value_float;
                        }
                        | C_STR
                        {
                                $$ = Value_string;
                        }
                        | c_bool
                        {
                                $$ = Value_boolean;
                        }
                        ;

c_bool  : TRUE
        | FALSE
        ;

var_name        : ID
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        $$ = id->value;
                }
                ;

array_refer     : ID LSB int_expression RSB
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        $$ = id->value;
                }
                ;

// Block
block   : block_begin block_content block_end
        ;

block_begin     : LCB
                {
                // symbolTableStack.push();
                // symbolTableSize++;
                // printf("%d\n",symbolTableSize);
                // symbolTableStack.tableStack[symbolTableSize].name = "block";
                }
                ;

block_end       : RCB
                {   
                        
                // symbolTableStack.pop();
                // symbolTableSize--;
                }
                ;

block_content   : block_content block_content
                | local_declaration
                | statements
                ;

// Conditional
condition_statement     : IF LB bool_expression RB block_or_simple_statement
                        | IF LB bool_expression RB block_or_simple_statement ELSE block_or_simple_statement
                        ;

// Loop
loop_statement  : WHILE LB bool_expression RB block_or_simple_statement
                | FOR LB ID num DOT DOT num  RB block_or_simple_statement


block_or_simple_statement       : block
                                | statements
                                ;

// Invocation
fun_invoc       : ID LB comma_separated_expressions RB
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        $$ = id->value;
                }
                ;

proc_invoc      : ID LB comma_separated_expressions RB
                {
                        Symbol * id=symbolTableStack.tableStack[symbolTableSize].lookup(*$1);
                        $$ = id->value;
                }
                ;

comma_separated_expressions     : comma_separated_expressions COMMA comma_separated_expressions
                                : expression
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
