%{
  #include <stdio.h>  
%}
%%
a|ab|abc|abcd { printf("%s\n", yytext); REJECT; }
.|\n { ; }
%%
int main() {
  yyin = fopen("input.txt", "r");
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
