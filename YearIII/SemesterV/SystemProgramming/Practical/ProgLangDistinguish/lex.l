%{
  int integers = 0;
  int floats = 0;
  int identifiers = 0;
  int operators = 0;
  int comments = 0;
%}
%%
[#].* { printf("%s <- preprocessor directive\n", yytext); } // preprocessor directives
[ |\n|\t] { ; } // whitespaces
[,|;|"("|")"|"{"|"}"|"\["|"\]"] { ; } // brackets, delimiters
"//".* { comments++; printf("%s <- comment\n", yytext); } // single line comments
[0-9]+ { integers++; printf("%s <- integer\n", yytext); } // integers
[0-9]+("."[0-9]+) { floats++; printf("%s <- float\n", yytext); } // floats
void|int|main|char|for|while|continue|switch|case|break|if|else|return|true|false { printf("%s <- keyword\n", yytext); } // keywords
"<="|">="|"!="|"=="|"<"|">"|"&"|"|"|"^"|"<<"|">>"|"~"|"&&"|"||"|"!"|"++"|"--"|"="|"+"|"-"|"*"|"/"|"%" { operators++; printf("%s <- operator\n", yytext); } // operators
[']([^\\\']|\\.)?['] { ; } // characters
["]([^\\\"]|\\.)*["] { ; } // strings
[a-zA-Z_]+[a-zA-Z0-9_]* { identifiers++; printf("%s <- identifier\n", yytext); } // identifiers
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  printf("\n");
  printf("number of integers: %d\n", integers);
  printf("number of floats: %d\n", floats);
  printf("number of identifiers: %d\n", identifiers);
  printf("number of operators: %d\n", operators);
  printf("number of comments: %d", comments);
  return 0;
}

int yywrap() {
  return 1;
}
