%{
  int vowels = 0;
  int consonants = 0;
%}
%%
A|E|I|O|U|a|e|i|o|u { vowels++; };
[A-Za-z] { consonants++; };
[ |\t|\n] { ; }
. { ; }
%%
int main()
{
  yylex();
  printf("%i vowels, %i consonants\n", vowels, consonants);
  return 0;
}

int yywrap()
{
  return 1;
}
