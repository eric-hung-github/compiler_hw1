%{
        #include <iostream>
        #include <stdio.h>
        #include <string>
        #include <memory.h>
        #include <stdlib.h>
        #include "symbol_table.hpp"
        #include "y.tab.hpp"

        #define MAX_LINE_LENG 256

        int linenum = 1;
        char buf[MAX_LINE_LENG];

        #define LIST     strcat(buf,yytext)
        #define token(t) {LIST; return t;}
        #define tokenInteger(t,i) {LIST; yylval.str_value = i;return t;}
        #define tokenString(t,s) {LIST; yylval.str_value = s;return t;}
        #define tokenFloat(t,f) {LIST; yylval.str_value = f;return t;}

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
                              char* temp=(char *)malloc(sizeof(char)*strlen(yytext));
                              strcpy(temp,yytext);
                              char* ptr=strstr(temp,"\"\"");
                              while(ptr!=NULL){
                                memmove(ptr,ptr+1, strlen(temp) - strlen(ptr+1));
                                ptr=strstr(temp,"\"\"");
                              }
                              tokenString(C_STR,temp);
                              }
                              
","     {token(DOT);}
";"     {token(FAN);}
":"     {token(MO);}
"->"    {token(ARROW);}
"."     {token(DOT);}
"("     {token(LB);}
")"     {token(RB);}
"{"     {token(LCB);}
"}"     {token(RCB);}
"["     {token(LSB);}
"]"     {token(RSB);}
"+"     {token(ADD);}
"-"     {token(SUB);}
"*"     {token(MUL);}
"/"     {token(DIV);}
"%"     {token(MOD);}
">"     {token(BT);}
"<"     {token(ST);}
"<="    {token(SET);}
"=>"    {token(BET);}
"=="    {token(EQL);}
"!="    {token(NEQ);}
"&"     {token(AND);}
"|"     {token(OR);}
"!"     {token(NOT);}
"="     {token(ASIGN);}
"+="    {token(ADDASIGN);}
"-="    {token(SUBASIGN);}
"*="    {token(MULASIGN);}
"/="    {token(DIVASIGN);}

bool            {token(BOOL);}
break           {token(BREAK);}
char            {token(CHAR);}
case            {token(CASE);}
class           {token(CLASS);}
continue        {token(CONTINUE);}
declare         {token(DECLARE);}
do              {token(DO);}
else            {token(ELSE);}
exit            {token(EXIT);}
false           {token(FALSE);}
float           {token(FLOAT);}
for             {token(FOR);}
fun             {token(FUN);}
if              {token(IF);}
int             {token(INT);}
loop            {token(LOOP);}
print           {token(PRINT);}
println         {token(PRINTLN);}
return          {token(RETURN);}
string          {token(STRING);}
true            {token(TRUE);}
val             {token(VAL);}
var             {token(VAR);}
while           {token(WHILE);}

{identifier}                    {tokenString(ID,yytext);
                                return ID;}

0|([1-9][0-9]*)                 {tokenInteger(C_INT, yytext);}

(0|([1-9][0-9]*))"."[0-9]+	{tokenFloat(C_FLOAT, yytext);}



\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }
<<EOF>> {
        LIST;
        printf("%d: %s\n", linenum++, buf);
        buf[0] = '\0';
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