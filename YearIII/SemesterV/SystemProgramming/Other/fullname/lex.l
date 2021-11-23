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
[A-Z][a-zA-Z]+ { return NAME; }
[ \t\n] { return yytext[0]; }
. { return yytext[0]; }
%%
