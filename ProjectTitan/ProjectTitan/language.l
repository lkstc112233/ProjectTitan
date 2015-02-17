%{
    int yylex(void);
#include "y.tab.h"
%}

%option noyywrap

%%
"("                     return LB;
")"                     return RB;
[A-Za-z_][A-Za-z_0-9]*  return IDENTIFIER;
%%

int yyerror()
{
    return 0;
}
