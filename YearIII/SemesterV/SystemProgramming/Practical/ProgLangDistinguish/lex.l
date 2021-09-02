%{
  int words = 0;
  int lines = 0;
  int spaces = 0;
  int characters = 0;
%}
%%
[A-Za-z]+ { words++; }
[\n] { lines++; }
[ ] { spaces++; }
. { characters++; }
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  printf("number of words: %d\n", words);
  printf("number of characters: %d\n", characters);
  printf("number of blank spaces: %d\n", spaces);
  printf("number of lines: %d\n", lines);
  return 1;
}

int yywrap() {
  return 1;
}
