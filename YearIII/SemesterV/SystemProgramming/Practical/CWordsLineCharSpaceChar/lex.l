%{
  int words = 0;
  int lines = 0;
  int spaces = 0;
  int characters = 0;
%}
%%
[A-Za-z0-9@$\\]+ { words++; characters += yyleng; }
[\n|\r] { lines++; characters += yyleng; }
[ |\t] { spaces++; characters += yyleng; }
. { characters++; }
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  printf("number of words: %d\n", words);
  printf("number of blank spaces: %d\n", spaces);
  printf("number of lines: %d\n", lines + 1);
  printf("number of characters: %d\n", characters);
  return 0;
}

int yywrap() {
  return 1;
}
