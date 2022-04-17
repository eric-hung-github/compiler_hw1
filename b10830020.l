%{
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",#t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}

#define MAX_LINE_LENG 256

int linenum = 1;
char buf[MAX_LINE_LENG];
%}

identifier[a-z|A-Z][a-z|A-Z|0-9]*
%Start  C_COMMENT
%Start  R_COMMENT
%Start  STRING

%%

"/*"            { BEGIN C_COMMENT ; }
<C_COMMENT>"*/" { BEGIN INITIAL ; }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

"//"            { BEGIN C_COMMENT; }
<R_COMMENT>"\n" { BEGIN INITIAL; }
<R_COMMENT>.    { }

"\""           { BEGIN STRING; }
<STRING>"\""    { BEGIN INITIAL; }
<STRING>.    { }

"("     {token('(');}
")"     {token(')');}
"{"     {token('{');}
"}"     {token('{');}

class   {token(CLASS)}
if      {token(IF)}
print     {token(PRINT)}

{identifier}    {tokenString(id,yytext);}


\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%