%{
#include "warper.h"
%}


%token  LB RB IDENTIFIER

%%
terminal:LB RB

identifiers
: IDENTIFIER {$$ = $1;}
| identifiers IDENTIFIER {$$ = $2;}
%%

