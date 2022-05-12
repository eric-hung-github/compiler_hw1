$make
$./executable helloword.kt

// <STRING>([^"\n)]|\"\")*      { 
//                               char* temp;
//                               strcpy(temp,yytext);
//                               char* ptr=strstr(temp,"\"\"");
//                               while(ptr!=NULL){
//                                 memmove(ptr,ptr+1, strlen(temp) - strlen(ptr+1));
//                                 ptr=strstr(temp,"\"\"");
//                               }
//                               tokenString(string,temp);
//                               }