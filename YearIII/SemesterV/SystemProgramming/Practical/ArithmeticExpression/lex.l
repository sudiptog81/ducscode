%{
  #include <stdio.h>
  int brackets = 0,
      operators = 0,
      numbersOridentifiers = 0,
      flag = 0;
%}
%%
[a-zA-Z_]+[a-zA-Z0-9_]* { numbersOridentifiers++; }
-?[0-9]+("."[0-9]+)? { numbersOridentifiers++; }
[+|\-|*|/|=|\^|%] { operators++; }
"(" { brackets++; }
")" { brackets--; }
";" { flag = 1; }
.|\n { ; }
%%
int main() {
  printf("Enter Arithmetic Expression: ");
  /* yyin = fopen("input.txt", "r"); */
  yylex();
  if (
    (operators + 1) == numbersOridentifiers
      && brackets == 0 && flag == 0
  ) {
    printf("Valid Expression\n");
  } else {
    printf("Invalid Expression\n");
  }
  return 0;
}

int yywrap() {
  return 1;
}
