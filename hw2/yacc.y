%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
// using namespace std;
#include "symbol_table.hpp"
#include "y.tab.hpp"

int yylex();
int yyerror(string s);

extern int linenum;
extern FILE *yyin;
extern char *yytext;
extern char buf[256];

SymbolTableStack symbolTableStack =  SymbolTableStack();

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
%token <str_value> ID C_STR
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



/* left */
%left AND OR NOT
%left BT ST SET BET EQL NEQ
%left ADD SUB MUL DIV 

%start program
%%

// Data Types
type    : INT
        | FLOAT
        | STRING
        | BOOL
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

const_declaration       : VAL ID ASIGN const_expression
                        | VAL ID type ASIGN const_expression

var_declaration         : VAR ID
                        | VAR ID MO type
                        | VAR ID MO type const_expression
                        | VAR ID const_expression
                        ;

array_declaration       : VAR ID MO type LSB num RSB
                        ;

// Program
program         : program_begin program_content program_end
                ;

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

program_end : RCB
    {
        programIsDeclare = false;
        symbolTableStack.pop();
        symbolTableSize--;
    }
    ;

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
                ;

proc_declaration: FUN ID LB formal_arguments RB block
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
                | ID LSB int_expression RSB ASIGN expression
                | PRINT LB expression RB
                | PRINTLN LB expression RB
                | RETURN ID
                | RETURN 
                | RETURN expression 
                ;

// Expression
const_expression        : expression
                        ;

int_expression          : expression
                        ;

bool_expression         : expression
                        ;

expression      : expression expression
                | SUB expression
                | expression math_operator expression
                | expression logic_operator expression
                | expression bit_operator expression
                | components
                ;

math_operator   : MUL DIV ADD SUB
                ;

logic_operator  : BT ST SET BET EQL NEQ
                ;

bit_operator    : AND OR NOT
                ;

// Expression component
components      : literal_constant
                | var_name
                | fun_invoc
                | array_refer
                ;

literal_constant        : C_INT 
                        | C_FLOAT
                        | C_STR
                        | c_bool
                        ;

c_bool  : TRUE
        | FALSE
        ;

var_name        : ID
                ;

array_refer     : ID LSB int_expression RSB
                ;

// Block
block   : LCB block_content RCB
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
                ;

proc_invoc      : ID LB comma_separated_expressions RB
                ;

comma_separated_expressions     : comma_separated_expressions COMMA comma_separated_expressions
                                : expression
                                ;

// Num
num     : C_INT
        ;

%%

int yyerror( string msg )
{
        fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
        fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
        std::cerr<<"| Error : " << msg <<endl;
        fprintf( stderr, "| Unmatched token: %s\n", yytext );
        fprintf( stderr, "|--------------------------------------------------------------------------\n" );
        exit(-1);
}

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
