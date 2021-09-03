%{
  int vowels = 0;
  int consonants = 0;
%}
%%
A|E|I|O|U|a|e|i|o|u { vowels++; };
[A-Za-z] { consonants++; };
[ |\n|\t||r] { ; }
. { ; }
%%
int main()
{
  yylex();
  printf("%i vowels, %i consonants", vowels, consonants);
  return 0;
}

int yywrap()
{
  return 1;
}
