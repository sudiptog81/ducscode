%{
  int length = 0;
  char *word = NULL;
%}

%%

[a-zA-Z]+ { 
  if (yyleng > length) {
    length = yyleng;
    word = yytext;
  }
}
[ |\n|\r|\t] { }
. { }

%%

int main(void) {
  yyin = fopen("input.txt", "r");
  yylex();
  fclose(yyin);
  printf("Longest Word: %.*s\n", length, word);
  printf("Length of Longest Word: %d\n", length);
  return 0;
}

int yywrap() {
  return 1;
}
