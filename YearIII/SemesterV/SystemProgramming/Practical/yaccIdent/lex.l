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
[a-z] { return L; }
[0-9] { return D; }
[ \t\n]+ { ; }
. { return yytext[0]; }
%%
