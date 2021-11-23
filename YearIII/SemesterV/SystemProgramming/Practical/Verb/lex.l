%%
is     |
am     |
are    |
were   |
was    |
be     |
being  |
been   |
do     |
does   |
did    |
will   |
would  |
should |
can    |
could  |
has    |
have   |
had    |
go        { printf("%s is a verb\n", yytext); }
[A-Za-z]+ { printf("%s is not a verb\n", yytext); }
[ |\t|\n] { ; }
. { ; }
%%
int main()
{
  yylex();
  return 0;
}

int yywrap()
{
  return 1;
}
