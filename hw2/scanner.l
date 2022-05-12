%{
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "y.tab.h"

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];

#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%s>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}
#define tokenFloat(t,f) {LIST; printf("<%s:%s>\n",#t,f);}


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
%Start  C_STRING

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

<INITIAL>"\""           {  LIST;BEGIN(C_STRING); }
<C_STRING>"\""            {  LIST;BEGIN(INITIAL); }
<C_STRING>([^"\n)]|\"\")*      { 
                              char* temp=malloc(sizeof(char)*strlen(yytext));
                              strcpy(temp,yytext);
                              char* ptr=strstr(temp,"\"\"");
                              while(ptr!=NULL){
                                memmove(ptr,ptr+1, strlen(temp) - strlen(ptr+1));
                                ptr=strstr(temp,"\"\"");
                              }
                              tokenString(string,temp);
                              return C_STR;
                              }
                              
","     {token(','); return DOT;}
";"     {token(';'); return FAN;}
":"     {token(':'); return MO;}
"->"    {token('->'); return ARROW;}
"."    {token('.'); return DOT;}

"("     {token('('); return LB;}
")"     {token(')'); return RB;}
"{"     {token('{'); return LCB;}
"}"     {token('}'); return RCB;}
"["     {token('['); return LSB;}
"]"     {token(']'); return RSB;}

"+"     {token('+'); return ADD;}
"-"     {token('-'); return SUB;}
"*"     {token('*'); return MUL;}
"/"     {token('/'); return DIV;}
"%"     {token('%'); return MOD;}

">"     {token('>'); return BT;}
"<"     {token('<'); return ST;}
"<="    {token(<=); return SET;}
"=>"    {token(>=); return BET;}
"=="    {token('=='); return EQL;}
"!="    {token('!='); return NEQ;}

"&"     {token('&'); return AND;}
"|"     {token('|'); return OR;}
"!"     {token('!'); return NOT;}

"="     {token('='); return ASIGN;}
"+="    {token('+='); return ADDASIGN;}
"-="    {token('-='); return SUBASIGN;}
"*="    {token('*='); return MULASIGN;}
"/="    {token('/='); return DIVASIGN;}

bool            {token(BOOL); return BOOL;}
break           {token(BREAK); return BREAK;}
char            {token(CHAR); return CHAR;}
case            {token(CASE); return CASE;}
class           {token(CLASS); return CLASS;}
continue        {token(CONTINUE); return CONTINUE;}
declare         {token(DECLARE); return DECLARE;}
do              {token(DO); return DO;}
else            {token(ELSE); return ELSE;}
exit            {token(EXIT); return EXIT;}
false           {token(FALSE); return FALSE;}
float           {token(FLOAT); return FLOAT;}
for             {token(FOR); return FOR;}
fun             {token(FUN); return FUN;}
if              {token(IF); return IF;}
int             {token(INT); return INT;}
loop            {token(LOOP); return LOOP;}
print           {token(PRINT); return PRINT;}
println         {token(PRINTLN); return PRINTLN;}
return          {token(RETURN); return RETURN;}
string          {token(STRING); return STRING;}
true            {token(TRUE); return TRUE;}
val             {token(VAL); return VAL;}
var             {token(VAR); return VAR;}
while           {token(WHILE); return WHILE;}

{identifier}                    {tokenString(id,yytext);
                                if(lookup(yytext)==0)insert(yytext);
                                return ID;}

0|([1-9][0-9]*)                 {tokenInteger(integer, yytext); return C_INT;}

(0|([1-9][0-9]*))"."[0-9]+	{tokenFloat(float, yytext); return C_FLOAT;}



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