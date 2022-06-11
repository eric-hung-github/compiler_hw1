%{
#include <iostream>
#include <fstream>
#include <string>
#include "symbol_table.hpp"
#include "lex.yy.cpp"
using namespace std;

#define Trace(t)        cout<<t<<endl;

// a=a+b segmentation fault

const string MAX_STACK = "15";
const string MAX_LOCALS = "15";

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
%type <value> components literal_constant var_refer fun_invoc proc_invoc num literal_constant_bool
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

                jasm("class "+*$2);
                jasm("{");

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

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"("+arguments+")");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                } block{
                        symbolTableStack.pop();
                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("}");

                }
                | FUN ID LB RB MO type_define
                {       
                        Symbol* symbol = new Symbol();
                        symbol->id_type = ID_FUNC;
                        symbol->name = *$2;   
 
                        symbolTableStack.insert(symbol);

                        symbolTableStack.push(*$2);

                        symbolTableStack.fun_ptr=symbol;

                        symbolTableStack.fun_ptr=symbol;
                        
                        // javaa
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"()");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("}");

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

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        
                        jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"("+arguments+")");
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");


                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("return");
                        
                        jasm("}");

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

                        if(symbol->name=="main"){
                                jasm("method public static void main(java.lang.String[])"); 
                        }else{
                                jasm("method public static "+ValueTypeToString(symbol->value->value_type)+" "+symbol->name+"()");
                        }
                        jasm("max_stack "+MAX_STACK);
                        jasm("max_locals "+MAX_LOCALS);
                        jasm("{");

                } block{
                        symbolTableStack.pop();

                        symbolTableStack.fun_ptr=nullptr;

                        // javaa
                        jasm("return");
                        jasm("}");

                }
                ;

formal_argument_list    : formal_argument COMMA formal_argument_list
                        | formal_argument
                        ;

formal_argument         : ID MO type_define
                        {       
                                Symbol* symbol = new Symbol();
                                symbol->id_type = ID_VAR;
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
                        symbolTableStack.update_value(symbol);
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
                | {
                        jasm("getstatic java.io.PrintStream java.lang.System.out");
                } print_statement
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
                                // javaa
                                jasm("ireturn");
                        }

                        
                }
                | RETURN
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if (symbolTableStack.fun_ptr->value->value_type!=VALUE_VOID)
                        {       
                                TypeError(symbolTableStack.fun_ptr->value->value_type,VALUE_VOID);
                        }
                        // javaa
                        jasm("return");
                        
                }
                | RETURN expression 
                {
                        if(!symbolTableStack.fun_ptr){
                                yyerror("Not in function");
                        }else if ($2->value_type!=symbolTableStack.fun_ptr->value->value_type)
                        {       
                                TypeError($2->value_type,symbolTableStack.fun_ptr->value->value_type);
                        }
                        // javaa
                        jasm("ireturn");
                }
                ;

print_statement : PRINT expression 
                {
                        symbolTableStack.print($2,false);
                }
                | PRINTLN  expression
                {
                        symbolTableStack.print($2,true);
                }

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

bool_expression         : literal_constant_bool
                        {
                                $$=$1;
                        }
                        |  expression logic_operator expression
                        {
                                if($1->value_type!=$3->value_type){
                                        TypeError($1->value_type,$3->value_type);
                                }
                                Value *ret=new Value();
                                ret->value_type=VALUE_BOOL;
                                $$=ret;

                                // javaa
                                jasm("isub");
                                jasm(*$2+" L"+to_string(symbolTableStack.tag));
                                jasm("iconst_0");
                                jasm("goto L"+to_string(symbolTableStack.tag+1));
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                jasm("iconst_1");
                                jasm("L"+to_string(symbolTableStack.tag+1)+": ");
                                symbolTableStack.tag+=2;
                        }
                        | bool_expression bit_operator bool_expression
                        {
                                if($1->value_type!=$3->value_type){
                                        TypeError($1->value_type,$3->value_type);
                                }
                                if($1->value_type!=VALUE_BOOL){
                                        TypeError($1->value_type,VALUE_BOOL);
                                }

                                $$=$1;

                                // javaa
                                jasm(*$2);
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
                | NOT expression
                {
                        if($2->value_type!=VALUE_BOOL){
                                TypeError($2->value_type,VALUE_BOOL);
                        }
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
                        string *op=new string("imul");
                        $$=op;
                }
                | DIV
                {
                        string *op=new string("idiv");
                        $$=op;
                }
                | ADD
                {
                        string *op=new string("iadd");
                        $$=op;
                }
                | SUB
                {
                        string *op=new string("isub");
                        $$=op;
                }
                | MOD
                {
                        string *op=new string("irem");
                        $$=op;
                }
                ;

logic_operator  : ST 
                {
                        string *op=new string("iflt");
                        $$=op;
                }
                | BT
                {
                        string *op=new string("ifgt");
                        $$=op;
                }
                | SET
                {
                        string *op=new string("ifle");
                        $$=op;
                }
                | BET
                {
                        string *op=new string("ifge");
                        $$=op;
                }
                | EQL
                {
                        string *op=new string("ifeq");
                        $$=op;
                }
                | NEQ
                {
                        string *op=new string("ifne");
                        $$=op;
                }
                ;

bit_operator    : AND
                {
                        string *op=new string("iand");
                        $$=op;
                }
                | OR
                {
                        string *op=new string("ior");
                        $$=op;
                }
                | NOT
                {
                        string *op=new string("ixor");
                        $$=op;
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
                        | literal_constant_bool
                        ;
literal_constant_bool   : TRUE 
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

                        if(symbol->id_type==ID_CONST){
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
condition_statement     : IF LB bool_expression RB 
                        {
                                jasm("ifeq L"+to_string(symbolTableStack.tag));
                        } block_or_simple_statement
                        {
                                jasm("goto L"+to_string(symbolTableStack.tag+1));
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        } else_statement
                        ; 

else_statement          : ELSE block_or_simple_statement
                        {
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        }
                        | 
                        {
                                jasm("L"+to_string(symbolTableStack.tag)+":");
                                symbolTableStack.tag+=1;
                        }
                        ;

// Loop
loop_statement  : WHILE
                {
                        jasm("L"+to_string(symbolTableStack.tag)+":");
                        symbolTableStack.temp_tag=symbolTableStack.tag;
                        symbolTableStack.tag+=1;
                } LB bool_expression RB 
                {
                        jasm("Lifeq L"+to_string(symbolTableStack.tag));
                } block_or_simple_statement
                {
                        jasm("goto L"+to_string(symbolTableStack.temp_tag));
                        jasm("L"+to_string(symbolTableStack.tag)+":");       
                }
                | FOR LB ID num DOT DOT num  RB 
                {
                        jasm("sipush "+$4->display());
                        jasm("istore 1");
                        jasm("L"+to_string(symbolTableStack.tag)+":");
                        jasm("iload 1");
                        jasm("sipush "+$7->display());
                        jasm("isub");
                        jasm("ifle L"+to_string(symbolTableStack.tag+1));
                        jasm("iconst_0");
                        jasm("goto L"+to_string(symbolTableStack.tag+2));

                        jasm("L"+to_string(symbolTableStack.tag+1));
                        jasm("iconst_1");

                        jasm("L"+to_string(symbolTableStack.tag+2));
                        jasm("Lifeq L"+to_string(symbolTableStack.tag+3));
                } block_or_simple_statement
                {
                        jasm("goto L"+to_string(symbolTableStack.tag));
                        jasm("L"+to_string(symbolTableStack.tag+3)+":");       
                        symbolTableStack.tag+=4;
                }
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

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("invokestatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name+"("+arguments+")");
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

                        // javaa                        
                        string arguments="";
                        for(int i=0;i<symbol->arguments.size();i++){
                                if(i!=0){
                                        arguments+=", ";
                                }
                                arguments+=ValueTypeToString(symbol->arguments[i]->value->value_type);
                        }
                        jasm("invokestatic "+ValueTypeToString(symbol->value->value_type)+" "+symbolTableStack.program_name+"."+symbol->name+"("+arguments+")");

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
                Value *value=new Value();
                value->value_type=VALUE_INT;
                value->int_value=$1;
                $$=value;
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
