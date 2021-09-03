%{
  int rot = 0;
%}
%%
[A-Z] { fprintf(yyout, "%c", (yytext[0] - 'A' + rot) % 26 + 'A'); }
[a-z] { fprintf(yyout, "%c", (yytext[0] - 'a' + rot) % 26 + 'a'); }
. { fprintf(yyout, "%s", yytext); }
%%
int main(void) {
  printf("Enter Key (ROT): ");
  scanf("%d", &rot);
  yyin = fopen("input.txt", "r");
  yyout = fopen("output.txt", "w");
  yylex();
  fclose(yyin);
  fclose(yyout);
  return 0;
}

int yywrap() {
  return 1;
}
