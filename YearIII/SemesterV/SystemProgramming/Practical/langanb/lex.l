/* lex.l */
%{
  #include <stdio.h>
  #include <stdlib.h>

  #if __has_include("y.tab.h")
    #include "y.tab.h"
  #endif
%}

%option noyywrap
%%
[a] { return A; }
[b] { return B; }
[ |\n|\t] { ; }
. { return yytext[0]; }
%%
