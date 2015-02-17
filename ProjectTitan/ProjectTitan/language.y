%{
#include "warper.h"
%}

%union
{
    void * pointer;
}

%token  LB RB NOCAL
%token<pointer> IDENTIFIER VALUE
%type <pointer> list items

%%


list : LB items RB          { makeList($2); }
list : LB RB                { makeEmptyList(); }

items
: items list                { addListToItems($2,$1); }
| items IDENTIFIER          { addIdentifierToItems($2,$1); }
| items VALUE               { addValueToItems($2,$1); }
| list                      { makeItemsWithList($1); }
| IDENTIFIER                { makeItemsWithIdentifier($1); }
| VALUE                     { makeItemsWithValue($1); }
;

%%

