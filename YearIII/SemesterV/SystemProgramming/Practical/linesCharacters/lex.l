%{
  int lines = 0;
  int characters = 0;
%}
%%
[\n] { lines++; }
[ ] { ; }
. { characters++; }
%%
int main() {
  yyin = fopen("input.txt", "r");
  yylex();
  printf("number of lines: %d\n", lines);
  printf("number of characters: %d", characters);
  return 1;
}

int yywrap() {
  return 1;
}
