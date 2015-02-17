%{
    int yylex(void);
#include "y.tab.h"
#include "warper.h"

%}

%option noyywrap

%%
"("                     return LB;
")"                     return RB;
\n                      ;
[A-Za-z_][A-Za-z_0-9]*  {yylval.pointer=newString(yytext);return IDENTIFIER;}
[-\+]?\d+(\.\d+)?       {yylval.pointer=newDouble(yytext);return VALUE;}
%%

int yyerror()
{
    return 0;
}
