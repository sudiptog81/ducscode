%{
  #include <stdio.h>  
%}
%%
[ \t\n]+ { fprintf(yyout, " "); }
. { fprintf(yyout, "%s", yytext); }
%%
int yywrap() { return 1; }

int main() {
  yyin = fopen("test.txt", "r");
  yyout = fopen("test.out", "w");
  yylex();
  fclose(yyin);
  fclose(yyout);
  return 0;
}
