%{
#define Trace(t) if (Opt_P) printf(t)
#include <iostream>
#include <string>
#include "symboltable.hpp"
#include "lex.yy.cpp"
int yylex();
int yyerror(char *msg);
using namespace std;

extern char buf[256];
extern char* yytext;
extern int linenum;
extern FILE *yyin;

int Opt_P = 1;
SymbolTableStack symbolTableStack = SymbolTableStack();
int currentStack = 0;
vector<Value* > args;
%}

%union{
    int type;
    int int_value;
    float float_value;
    bool bool_value;
    string* str_value;
    Value* value;
    Symbol* symbol;
}
/* tokens */
%token <str_value> id
%token <int_value> int_find
%token <str_value> str_find
%token <bool_value> bool_find
%token <float_value> float_find


%type <type> type biOperator
%type <value> dataValue expression params param funcInvoc function arrayRefer
%type <value> intExpression boolExpression constExpression

%token CHAR ADD_ASSIGN MINUS_ASSIGN PROD_ASSIGN DEVIED_ASSIGN
%token AND OR NOT EQU NOT_EQU LESS LESS_EQU MORE MORE_EQU 
%token ASSIGN ARROW
%token VAL VAR FUN BOOL INT FLOAT STRING DECLARE
%token BLOCK_BEGIN BLOCK_END RETURN
%token FOR IN DOTDOT IF WHILE DO ELSE CONTINUE BREAK CASE EXIT LOOP
%token CLASS
%token PRINT PRINTLN 

%left NOT
%nonassoc UMINUS

%%


//program
program: programBegin BLOCK_BEGIN programContents BLOCK_END{
    symbolTableStack.pop();
    currentStack--;
}
;

programBegin: CLASS id {
    //creat globol table
    symbolTableStack.push();
    symbolTableStack.tableStack[0].name = *$2;
    
    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->type = IDProgram;
    symbolTableStack.tableStack.back().insert(symbol);
};

programContents: programContents programContent
|programContent
|
;

programContent: declareConstant
|declareVariable
|function
|procedure
|//empty
;

//procedure & function

function: funcBegin procedure_params ':' type{
    symbolTableStack.tableStack[0].symbols.back()->type = IDFunc;
    symbolTableStack.tableStack[0].symbols.back()->returnType = $4;

} block{
    symbolTableStack.pop();
    currentStack--;
}

procedure: funcBegin procedure_params {
    symbolTableStack.tableStack[0].symbols.back()->type = IDProcedure;
}
block{
    symbolTableStack.pop();
    currentStack--;
}
;

funcBegin: FUN id {
    symbolTableStack.push();
    currentStack++;
    symbolTableStack.tableStack.back().name = *$2;
    //insert symbol into globol table
    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    args.clear();

    symbolTableStack.tableStack[0].insert(symbol);
}
;

procedure_params: '(' params ')'{
    symbolTableStack.tableStack[0].symbols.back()->params = args;
}
;

params: params ',' param{
}
|param{
}
|//empty
;

param: id ':' type{
    Symbol* symbol = new Symbol();
    symbol->name = *$1;
    symbol->type = IDVariable;
    symbol->value->valuetype = $3;
    symbolTableStack.tableStack[currentStack].insert(symbol);
    args.push_back(symbol->value);
    $$ = symbol->value;
};


block: BLOCK_BEGIN statements BLOCK_END
;

//statement
statements: simpleStatement statements
|conditionalStatement statements
|loopStatement statements
|procedureInvoc statements
|//empty
;

statement: simpleStatement
|conditionalStatement
|loopStatement
;

simpleStatement:id ASSIGN expression
|id arrayRefer ASSIGN expression
|PRINT '(' expression ')'
|PRINT expression
|PRINTLN '(' expression ')'
|RETURN
|RETURN expression
;

conditionalStatement:IF '(' boolExpression ')' blockOrSimpleStatement 
|IF '(' boolExpression ')' blockOrSimpleStatement ELSE blockOrSimpleStatement
;

loopStatement:whileLoop
|forLoop
;

whileLoop: WHILE '(' boolExpression ')' blockOrSimpleStatement
;

forLoop: FOR '(' id IN intExpression DOTDOT intExpression ')' blockOrSimpleStatement
;

blockOrSimpleStatement: block
|simpleStatement
;

//expression

expression:
'(' expression ')'
|'-' expression %prec UMINUS{
    $$ = $2;
    $$->intNum = -($$->intNum);
}
|NOT expression{
    $$ = $2;
    $$->boolNum = !($$->boolNum);
}
|expression biOperator expression
|dataValue
|id{
    Symbol* symbol = symbolTableStack.lookup(*$1);
    $$ = symbol->value;
}
|funcInvoc
|id arrayRefer
;

constExpression: expression
;

intExpression: expression
;

boolExpression: expression
;

dataValue: int_find{
    Value* value = new Value();
    value->valuetype = ValueInt;
    value->intNum = $1;
    $$ = value;
}
|float_find{
    Value* value = new Value();
    value->valuetype = ValueFloat;
    value->floatNum = $1;
    $$ = value;
}
|bool_find{
    Value* value = new Value();
    value->valuetype = ValueBool;
    value->boolNum = $1;
    $$ = value;
}
|str_find{
    Value* value = new Value();
    value->valuetype = ValueString;
    value->strNum = *$1;
    $$ = value;
}
;


//declare


declareConstant: VAL id ':' type ASSIGN constExpression{
    Symbol* symbol = new Symbol();
    symbol->value = $6;
    symbol->type = IDConstant;
    symbol->name = *$2;
    
    symbolTableStack.tableStack.back().insert(symbol);

    if(currentStack != 0){
        //local constant
        
    }
    else{
        //globol constant

    }
}
|VAL id ASSIGN constExpression{
    Symbol* symbol = new Symbol();
    symbol->value = $4;
    symbol->type = IDConstant;
    symbol->name = *$2;
    
    symbolTableStack.tableStack.back().insert(symbol);
    
    if(currentStack != 0){
        //local constant
    }
    else{
        //globol constant
    }
}
;


declareVariable: VAR id ':' type{
    Symbol* symbol = new Symbol();
    symbol->type = IDVariable;
    symbol->value->valuetype = $4;
    symbol->name = *$2;
    symbolTableStack.tableStack.back().insert(symbol);
    if(currentStack == 0){
        //globol var
    }
    else{
        //local var
    }

}
|VAR id ':' type ASSIGN constExpression{
    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->value = $6;
    symbol->type = IDVariable;

    symbolTableStack.tableStack.back().insert(symbol);

    if(currentStack != 0){
        //local var
    }
    else{
        //globol var
    }

} 
|VAR id ASSIGN constExpression{
    Symbol* symbol = new Symbol();
    symbol->value = $4;
    symbol->type = IDVariable;
    symbol->name = *$2;

    symbolTableStack.tableStack.back().insert(symbol);

    if(currentStack != 0){
        //local var
    }
    else{
        //globol var
    }

}
|VAR id{
    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->value->valuetype = ValueInt;
    symbol->type = IDVariable;

    symbolTableStack.tableStack.back().insert(symbol);

    if(currentStack == 0){
        //globol var
    }
    else{
        //local var
    }

}
;

declareArray: VAR id ':' type arrayRefer{
    Symbol* symbol = new Symbol();
    symbol->name = *$2;
    symbol->arrayType = $4;
    symbol->arraySize = $5;
    symbolTableStack.tableStack[currentStack].insert(symbol);
}
;

arrayRefer: '[' intExpression ']'{
    $$ = $2;
}
;

biOperator: 
'*'
|'/'
|'+'
|'-'
|LESS
|LESS_EQU
|EQU
|MORE
|MORE_EQU
|NOT_EQU
|NOT
|AND
|OR
;

type: INT{
    $$ = ValueInt;
}
|FLOAT{
    $$ = ValueFloat;
}
|BOOL{
    $$ = ValueBool;
}
|STRING{
    $$ = ValueString;
}
;


//funcInvoc
funcInvoc: id '(' invocExpressions ')'
;

//procedureInvoc
procedureInvoc: id '(' invocExpressions ')'
;

//invocExpression
invocExpressions: expression ',' invocExpressions
|expression
|//empty
;

%%

int main(int argc, char* argv[]){
    FILE *fp = fopen( argv[1], "r" );

    if( fp == NULL )  {
        fprintf( stdout, "Open  file  error\n" );
        exit(-1);
    }

    yyin = fp;

    //fprintf(stdout, "hellomotherfucker.\n");
    if(yyparse()==1){
        yyerror("parsing error.");
    }

    fprintf( stdout, "\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    fprintf( stdout, "|  There is no syntactic error!  |\n" );
    fprintf( stdout, "|--------------------------------|\n" );
    exit(0);
}

int yyerror( char *msg )
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
    fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
    fprintf( stderr, "|\n" );
    fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}