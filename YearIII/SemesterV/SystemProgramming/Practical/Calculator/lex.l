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
[0-9]+(\.[0-9]+)? { yylval.f = atof(yytext); return NUM; }
[\-+()*/] { return yytext[0]; }
[ \t\n]+ { ; }
%%
