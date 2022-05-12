%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

int yylex();
int yyerror( char *msg );

extern int linenum;
extern FILE *yyin;
extern char *yytext;
extern char buf[256];

%}

%token SEMICOLON

%token COMMA
%token FAN
%token MO
%token ARROW
%token DOT

%token LB
%token RB
%token LCB
%token RCB
%token LSB
%token RSB

%token ADD
%token SUB
%token MUL
%token DIV
%token MOD

%token BT
%token ST
%token SET
%token BET
%token EQL
%token NEQ

%token AND
%token OR
%token NOT

%token ASIGN
%token ADDASIGN
%token SUBASIGN
%token MULASIGN
%token DIVASIGN

%token ID
%token C_INT
%token C_FLOAT
%token C_STR

%token BOOL
%token BREAK
%token CHAR
%token CASE
%token CLASS
%token CONTINUE
%token DECLARE
%token DO
%token ELSE
%token EXIT
%token FALSE
%token FLOAT
%token FOR
%token FUN
%token IF
%token INT
%token LOOP
%token PRINT
%token PRINTLN
%token RETURN
%token STRING
%token TRUE
%token VAL
%token VAR
%token WHILE


%%

// program
program         : cls_declaration_list
                ;

cls_declaration_list    : cls_declaration_list cls_declaration
                        | cls_declaration
                        ;

// class
cls_declaration : CLASS ID LCB class_body RCB
                ;

class_body      : global_declaration_list global_declaration
                | global_declaration
                ;

global_declaration_list : global_declaration_list global_declaration
                        | global_declaration
                        ;

global_declaration      : fun_declaration
                        | proc_declaration
                        | glob_var_declaration
                        ;



//function
fun_declaration : FUN fun_name LB arguments RB MO type block
                | FUN fun_name LB arguments RB block
                ;

fun_name        : ID
                ;

proc_declaration: FUN proc_name LB arguments RB block
                ;

proc_name        : ID
                ;

arguments       : arguments COMMA arg
                | arg
                |
                ;

arg : ID MO type
    ;

block   : LCB block_content RCB
        ;

block_content   : statement_list
                | local_var_declaration

//Statement
statement_list  : statement_list statement
                | statement
                ;

statement       : simple_statement
                | condition_statement
                | loop_statement
                ;

simple_statement: ID ASIGN expression
                | ID LSB int_expression RSB expression
                | PRINT LB expression RB
                | PRINTLN LB expression RB
                | RETURN
                | RETURN ID
                | RETURN expression 
                | proc_invoc
                ;

condition_statement     : IF LB bool_expression RB block_or_simple_statement
                        | IF LB bool_expression RB block_or_simple_statement ELSE block_or_simple_statement

loop_statement  : WHILE LB bool_expression RB block_or_simple_statement
                | FOR LB ID int_expression DOT DOT int_expression  RB block_or_simple_statement

block_or_simple_statement       : LCB block RCB
                                | statement


//Expression
expression      : SUB expression
                | expression MUL expression
                | expression DIV expression
                | expression ADD expression
                | expression SUB expression 
                | expression MOD expression
                | LB expression RB
                | bool_expression
                | logic_expression
                | constant
                | fun_invoc
                | ID
                | array_refer
                ;

bool_expression : expression BT expression
                | expression ST expression
                | expression SET expression
                | expression BET expression 
                | expression EQL expression 
                | expression NEQ expression
                ;

logic_expression: expression AND expression
                | expression OR expression
                | expression NOT expression
                ;

fun_invoc       : fun_name LB argument_input_list RB
                ;

proc_invoc      : proc_name LB argument_input_list RB
                ;

argument_input_list     : argument_input_list COMMA expression
                        | expression
                        | 
                        ;

constant        : C_FLOAT
                | C_INT
                | C_STR
                | TRUE
                | FALSE
                ;

array_refer     : ID LSB int_expression RSB
                ;

//variable
glob_var_declaration    : var_declaration
                        ;

local_var_declaration    : var_declaration
                        ;

var_declaration : VAR ID MO type
                | VAR ID EQL constant
                | VAR ID type EQL constant
                | VAR ID MO type LSB C_INT RSB
                ;

type    : INT
        | FLOAT
        | STRING
        | BOOL
        ;

int_expression  : ID

//Data Types and Declarations
/* data_declarations: datas
                 |
                 ;
datas: datas data_declaration
     | data_declaration
     ;
data_declaration: var_declaration | con_declaration
                ;
var_declaration : VAR idlist MO scalar_type FAN
                ;

con_declaration : VAR idlist MO litcons FAN
                ;
idlist  : idlist DOT ID
        | ID
        ;

litcons : INT | STRING | FLOAT | TRUE | FALSE
        ;

//Statements
compound_statement  : LCB data_declarations statements RCB
                    ;

statements: ss
          | 
          ;
ss: ss statement
  | statement
  ;
statement: compound_statement| simple_statement| condition | while | for | return |stfuncinvo;
statement: simple_statement | return |stfuncinvo;


simple_statement: PRINT expr FAN
                ;

var_ref : ID
        ;

operand : litcons
        | idlist
        | funcinvo
        | var_ref
        ;
boolexpr : operand ST operand 
         | operand BT operand
         | operand SET operand 
         | operand BET operand
         | operand EQL operand
         | operand NEQ operand
         ;
expr: SUB expr
    | expr ADD expr
    | expr SUB expr 
    | expr MUL expr
    | expr DIV expr
    | expr MOD expr
    | boolexpr
    | LB expr RB
    | expr AND expr
    | expr OR expr
    | NOT expr
    | litcons
    | idlist
    | funcinvo
    | var_ref
    ;


condition: IF expr THEN statements ELSE statements KWEND KWIF
         | IF expr THEN statements END IF
         ;
while: KWWHILE expr KWDO statements KWEND KWDO
     ;

for : FOR ID ME  integer KWTO integer KWDO statements KWEND KWDO
    ;

return : RETURN expr FAN
       ;
funcinvo: ID LB exprss RB
        ;
stfuncinvo  : funcinvo FAN
            ;
exprss  : exprs
        |
        ;
exprs: exprs DOT expr
     | expr
     ; */

%%

int yyerror( char *msg )
{
  fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
    fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
    fprintf( stderr, "|\n" );
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
