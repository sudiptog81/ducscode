%{
  int words = 0;
  int lines = 0;
  int spaces = 0;
  int characters = 0;
%}
%%
[^ \t\n,\.:;]+ { words++; characters += yyleng; }
[\n] { lines++; characters += yyleng; }
[ |\t] { spaces++; characters += yyleng; }
. { characters++; }
%%
int main() {
  yyin = fopen("text.txt", "r");
  yylex();
  printf("number of words: %d\n", words);
  printf("number of blank spaces: %d\n", spaces);
  printf("number of lines: %d\n", lines);
  printf("number of characters: %d\n", characters);
  return 0;
}

int yywrap() {
  return 1;
}
