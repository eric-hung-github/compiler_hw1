%{
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%s>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}
#define tokenFloat(t,f) {LIST; printf("<%s:%s>\n",#t,f);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct symrec
{
  char *name;
};
typedef struct symrec symrec;
symrec sym_table[256];

int table_counter=0;

void create(){
  table_counter=0;
}

void dump(){
  table_counter=0;
}

int insert ( char *sym_name ){
  table_counter=table_counter+1;
  sym_table[table_counter].name = (char *) malloc (strlen(sym_name)+1);
  strcpy (sym_table[table_counter].name,sym_name);
  return table_counter;
}

int lookup ( char *sym_name ){
  for(int i=1;i<=table_counter;i++){
    if(strcmp (sym_table[i].name,sym_name) == 0){
      return i;
    }
  }
  return 0;
}

%}

%option noyywrap

identifier[a-z|A-Z][a-z|A-Z|0-9]*
%Start  C_COMMENT
%Start  R_COMMENT
%Start  STRING

%%

<INITIAL>"/*"           { LIST;BEGIN(C_COMMENT); }
<C_COMMENT>"*/"         {  LIST;BEGIN(INITIAL); }
<C_COMMENT>\n           { LIST;
                                printf("%d: %s", linenum++, buf);
                                buf[0] = '\0'; }
<C_COMMENT>[^*\n]*      { LIST;}
<C_COMMENT>"*"+[^*/\n]* {  LIST;}

<INITIAL>"//"           {  LIST;BEGIN(R_COMMENT); }
<R_COMMENT>"\n"         {  LIST;BEGIN(INITIAL);
                                printf("%d: %s", linenum++, buf);
                                buf[0] = '\0'; }
<R_COMMENT>[^\n]*	{ LIST;}

<INITIAL>"\""           {  LIST;BEGIN(STRING); }
<STRING>"\""            {  LIST;BEGIN(INITIAL); }
<STRING>([^"\n)]|\"\")*      { 
                              char* temp=malloc(sizeof(char)*strlen(yytext));
                              strcpy(temp,yytext);
                              char* ptr=strstr(temp,"\"\"");
                              while(ptr!=NULL){
                                memmove(ptr,ptr+1, strlen(temp) - strlen(ptr+1));
                                ptr=strstr(temp,"\"\"");
                              }
                              tokenString(string,temp);
                              }

","     {token(',');}
":"     {token(':');}
";"     {token(';');}
"->"    {token('->');}

"("     {token('(');}
")"     {token(')');}
"{"     {token('{');}
"}"     {token('}');}
"["     {token('[');}
"]"     {token(']');}

"+"     {token('+');}
"-"     {token('-');}
"*"     {token('*');}
"/"     {token('/');}
"%"     {token('%');}

"<"     {token('<');}
">"     {token('>');}
"<="    {token('<=');}
">="    {token('>=');}
"=="    {token('==');}
"!="    {token('!=');}

"&"     {token('&');}
"|"     {token('|');}
"!"     {token('!');}

"="     {token('=');}
"+="    {token('+=');}
"-="    {token('-=');}
"*="    {token('*=');}
"/="    {token('/=');}

bool            {token(BOOL)}
break           {token(BREAK)}
char            {token(CHAR)}
case            {token(CASE)}
class           {token(CLASS)}
continue        {token(CONTINUE)}
declare         {token(DECLARE)}
do              {token(DO)}
else            {token(ELSE)}
exit            {token(EXIT)}
false           {token(FALSE)}
float           {token(FLOAT)}
for             {token(FOR)}
fun             {token(FUN)}
if              {token(IF)}
int             {token(INT)}
loop            {token(LOOP)}
print           {token(PRINT)}
println         {token(PRINTLN)}
return          {token(RETURN)}
string          {token(STRING)}
true            {token(TRUE)}
val             {token(VAL)}
var             {token(VAR)}
while           {token(WHILE)}

{identifier}                    {tokenString(id,yytext);
                                if(lookup(yytext)==0)insert(yytext);}

0|([1-9][0-9]*)                 {tokenInteger(integer, yytext);}

(0|([1-9][0-9]*))"."[0-9]+	{tokenFloat(float, yytext);}



\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }
<<EOF>> {
        LIST;
        printf("%d: %s\n", linenum++, buf);
        buf[0] = '\0';
        printf("Symbol Table:\n");
        for(int i=1;i<=table_counter;i++){
          printf("%s\n",sym_table[i].name);
        }
        return 0;
        }
[ \t]  {LIST;}
.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%

int main( int argc, char **argv )
{
  if( argc != 2 ) {
    fprintf( stderr, "Usage: ./scanner input.txt\n" );
    exit(0);
  }
	
  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    exit(-1);
  }
	
  yyin = fp;

  yylex();

  exit(0);
}