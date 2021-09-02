%%

is|am|was|were { printf("%s is a verb", yytext); }
[A-Za-z]+ { printf("%s is not a verb", yytext); }

%%

int main()
{
  yylex();
  return 1;
}

int yywrap()
{
  return 1;
}
