%{
#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;

#define Trace(t)        cout<<t<<endl;
#define MAX_STACK 15
#define MAX_LOCALS 15
// a=a+b segmentation fault

int yylex();

void yyerror(string s)
{
    cout<<"ERROR LINE<"+to_string(linenum)+">: " << s <<endl;
    exit(-1);
}

void TypeError(int a,int b){
        yyerror("Type Error: "+ValueTypeToString(a)+" <-> "+ ValueTypeToString(b));
}

SymbolTableStack symbolTableStack =  SymbolTableStack();


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
%type <value> components literal_constant var_refer fun_invoc proc_invoc num
%type <symbol> arr_refer
%type <str_value> math_operator logic_operator bit_operator
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
                symbolTableStack.program_name=*$2;

                jasm("class "+*$2+"\n{");

                };

program_end     : RCB
                {
                        jasm("}");
                }
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
                                symbol->init=true;

                                symbolTableStack.insert(symbol);
                        }
                        | VAL ID MO type_define ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_CONST;
                                symbol->name = *$2;    
                                symbol->value= $6;
                                symbol->init=true;

                                if(symbol->value->value_type==$4){
                                        
                                        symbolTableStack.insert(symbol);
                                }else{
                                        TypeError(symbol->value->value_type,$4);
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
                                symbol->init=true;

                                if(symbol->value->value_type==$4){
                                        symbolTableStack.insert(symbol);
                                }else{
                                        TypeError(symbol->value->value_type,$4);
                                }
                        }
                        | VAR ID ASIGN const_expression
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
                                symbol->name = *$2;  
                                symbol->value= $4;
                                symbol->init=true;

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

                        symbolTableStack.push(*$2);
                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;

                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                }
                | FUN ID LB RB MO type_define
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *$2;   
 
                        symbolTableStack.insert(symbol);

                        symbolTableStack.push(*$2);

                        symbolTableStack.fun_ptr=symbol;

                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                }
                ;

proc_declaration: FUN ID LB formal_argument_list RB
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *$2;   
 
                        symbol->value->value_type= VALUE_VOID;

                        symbolTableStack.insert(symbol);

                        symbol->arguments=symbolTableStack.argumentStack;

                        symbolTableStack.push(*$2);
                        for(int i=0;i<symbolTableStack.argumentStack.size();i++){
                            symbolTableStack.insert(symbolTableStack.argumentStack[i]); 
                        }

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;


                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                }
                | FUN ID LB RB
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_PROCEDURE;
                        symbol->name = *$2;   
 
                        symbol->value->value_type= VALUE_VOID;
 
                        symbolTableStack.insert(symbol);


                        symbolTableStack.push(*$2);

                        symbolTableStack.argumentStack.clear();

                        symbolTableStack.fun_ptr=symbol;


                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

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
                                TypeError(symbol->value->value_type,$3->value_type);
                        }
                }
                | arr_refer ASIGN expression
                {
                        Symbol* symbol = $1;
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_ARR)
                        {
                                yyerror("ID is not array");
                        }else if (symbol->value->value_type!=$3->value_type)
                        {       
                                TypeError(symbol->value->value_type,$3->value_type);
                        }
                }
                | PRINT LB expression RB
                | PRINT expression 
                | PRINTLN LB expression RB
                | PRINTLN expression
                | RETURN ID
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else{
                                Symbol* symbol = symbolTableStack.lookup(*$2);
                                if (!symbol)
                                {
                                        yyerror("ID not found");
                                }else if (symbol->value->value_type!=symbolTableStack.fun_ptr->value->value_type)
                                {       
                                        TypeError(symbol->value->value_type,symbolTableStack.fun_ptr->value->value_type);
                                }
                        }
                }
                | RETURN
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if (symbolTableStack.fun_ptr->value->value_type!=VALUE_NONE)
                        {       
                                TypeError(symbolTableStack.fun_ptr->value->value_type,VALUE_NONE);
                        }
                        
                }
                | RETURN expression 
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if ($2->value_type!=symbolTableStack.fun_ptr->value->value_type)
                        {       
                                TypeError($2->value_type,symbolTableStack.fun_ptr->value->value_type);
                        }
                }
                ;

// Expression
const_expression        : LB const_expression RB
                        {
                                $$=$2;
                        }
                        | SUB const_expression
                        {
                                if($2->value_type!=VALUE_INT&&$2->value_type!=VALUE_FLOAT){
                                        TypeError($2->value_type,$2->value_type);
                                }
                                $$=$2;
                        }
                        | const_expression math_operator const_expression
                        {
                                if($1->value_type!=$3->value_type){
                                        TypeError($1->value_type,$3->value_type);
                                }
                                if($1->value_type!=VALUE_INT&&$1->value_type!=VALUE_FLOAT){
                                TypeError($1->value_type,$3->value_type);
                        }
                                $$=$1;
                        }
                        | const_expression logic_operator const_expression
                        {
                                if($1->value_type!=$3->value_type){
                                        TypeError($1->value_type,$3->value_type);
                                }
                                Value *ret=new Value();
                                ret->value_type=VALUE_BOOL;
                                $$=ret;
                        }
                        | const_expression bit_operator const_expression
                        {
                                if($1->value_type!=$3->value_type){
                                        TypeError($1->value_type,$3->value_type);
                                }
                                if($1->value_type!=VALUE_BOOL){
                                        TypeError($1->value_type,VALUE_BOOL);
                                }
                                $$=$1;
                        }
                        | literal_constant
                        {
                                $$=$1;
                        }
                        ;

int_expression          : expression
                        {
                                if($1->value_type!=VALUE_INT){
                                        TypeError($1->value_type,VALUE_INT);
                                }
                                $$=$1;
                        }
                        ;

bool_expression         : expression
                        {
                                if($1->value_type!=VALUE_BOOL){
                                        TypeError($1->value_type,VALUE_BOOL);
                                }
                                $$=$1;
                        }
                        ;

expression      : LB expression RB
                {
                        $$=$2;
                }
                | SUB expression
                {
                        if($2->value_type!=VALUE_INT&&$2->value_type!=VALUE_FLOAT){
                                TypeError($2->value_type,$2->value_type);
                        }
                        jasm("ineg");
                        $$=$2;
                }
                | expression math_operator expression
                {
                        if($1->value_type!=$3->value_type){
                                TypeError($1->value_type,$3->value_type);
                        }
                        if($1->value_type!=VALUE_INT&&$1->value_type!=VALUE_FLOAT){
                                TypeError($1->value_type,$3->value_type);
                        }
                        jasm(*$2);
                        $$=$1;
                }
                | expression logic_operator expression
                {
                        if($1->value_type!=$3->value_type){
                                TypeError($1->value_type,$3->value_type);
                        }
                        Value *ret=new Value();
                        ret->value_type=VALUE_BOOL;
                        jasm(*$2);
                        $$=ret;
                }
                | bool_expression bit_operator bool_expression
                {
                        if($1->value_type!=$3->value_type){
                                TypeError($1->value_type,$3->value_type);
                        }
                        if($1->value_type!=VALUE_BOOL){
                                TypeError($1->value_type,VALUE_BOOL);
                        }
                        jasm(*$2);
                        $$=$1;
                }
                | NOT bool_expression
                {
                        jasm("ixor");
                        $$=$2;
                }
                | components
                {
                        $$=$1;
                }
                ;

math_operator   : MUL 
                {
                        string op="imul";
                        $$=&op;
                }
                | DIV
                {
                        string op="idiv";
                        $$=&op;
                }
                | ADD
                {
                        string op="iadd";
                        $$=&op;
                }
                | SUB
                {
                        string op="isub";
                        $$=&op;
                }
                | MOD
                {
                        string op="irem";
                        $$=&op;
                }
                ;

logic_operator  : BT 
                {
                        string op="iflt";
                        $$=&op;
                }
                | ST
                {
                        string op="ifgt";
                        $$=&op;
                }
                | SET
                {
                        string op="ifle";
                        $$=&op;
                }
                | BET
                {
                        string op="ifge";
                        $$=&op;
                }
                | EQL
                {
                        string op="ifeq";
                        $$=&op;
                }
                | NEQ
                {
                        string op="ifne";
                        $$=&op;
                }
                ;

bit_operator    : AND
                {
                        string op="iand";
                        $$=&op;
                }
                | OR
                {
                        string op="ior";
                        $$=&op;
                }
                | NOT
                {
                        string op="ixor";
                        $$=&op;
                }
                ;

// Component
components      : literal_constant
                {
                        switch ($1->value_type)
                        {
                        case VALUE_INT:
                                jasm("sipush " + $1->display());
                                break;
                        case VALUE_BOOL:
                                jasm("iconst_" + $1->display());
                                break;
                        case VALUE_FLOAT:
                                jasm("sipush " + $1->display());
                                break;
                        case VALUE_STR:
                                jasm("ldc \"" + $1->display() + "\"");
                                break;
                        default:
                                break;
                        }
                        $$=$1;
                }
                | var_refer
                {
                        $$=$1;
                }
                | fun_invoc
                {
                        $$=$1;
                }
                | arr_refer
                {
                        $$=$1->value;
                }
                ;

literal_constant        : C_INT 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_INT;
                                value->int_value=$1;
                                $$=value;
                        }
                        | C_FLOAT 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_FLOAT;
                                value->float_value=$1;
                                $$=value;
                        }
                        | C_STR 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_STR;
                                value->string_value=*$1;
                                $$=value;
                        }
                        | TRUE 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                value->bool_value=true;
                                $$=value;
                        }
                        | FALSE 
                        {
                                Value* value=new Value();
                                value->value_type = VALUE_BOOL;
                                value->bool_value=false;
                                $$=value;
                        }
                        ;


var_refer        : ID
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }

                        if(symbol->id_type=ID_CONST){
                                symbolTableStack.load_value(symbol);
                        }else{ 
                                if(symbol->is_global){
                                        jasm("getstatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name);
                                }else{
                                        symbolTableStack.load_value(symbol);
                                }
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
                        $$ = symbol;
                }
                ;

// Block
block   : LCB 
        {
                
        } 
        block_contents
        {
                
        } RCB
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

block_or_simple_statement       : 
                                {       
                                        symbolTableStack.push("simple code block");

                                } block
                                {
                                        symbolTableStack.pop();
                                }
                                | simple_statement
                                ;

// Invocation
fun_invoc       : ID LB comma_separated_expressions RB
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_FUNC)
                        {
                                yyerror("ID is not function");
                        }else{
                                for(int i=0;i<symbol->arguments.size();i++){
                                        if(symbolTableStack.parseStack[i]->value_type!=symbol->arguments[i]->value->value_type){
                                                TypeError(symbolTableStack.parseStack[i]->value_type,symbol->arguments[i]->value->value_type);
                                        }
                                }
                        }

                        symbolTableStack.parseStack.clear();


                        $$ = symbol->value;
                }
                ;

proc_invoc      : ID LB comma_separated_expressions RB
                {
                        Symbol* symbol = symbolTableStack.lookup(*$1);
                        if (!symbol)
                        {
                                yyerror("ID not found");
                        }else if (symbol->id_type!=ID_PROCEDURE)
                        {
                                yyerror("ID is not procedure");
                        }else{
                                for(int i=0;i<symbol->arguments.size();i++){
                                        if(symbolTableStack.parseStack[i]->value_type!=symbol->arguments[i]->value->value_type){
                                                TypeError(symbolTableStack.parseStack[i]->value_type,symbol->arguments[i]->value->value_type);
                                        }
                                }
                        }

                        symbolTableStack.parseStack.clear();


                        $$ = symbol->value;
                }
                ;

comma_separated_expressions     : expression 
                                {
                                        symbolTableStack.parseStack.push_back($1);
                                } COMMA comma_separated_expressions
                                | expression
                                {
                                        symbolTableStack.parseStack.push_back($1);
                                }
                                ;

// Num
num     : C_INT
        {
                Value *ret=new Value();
                ret->value_type=VALUE_INT;
                $$=ret;
        }
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

	yyin = fp;
	yyparse();

        jasm_file.close();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
