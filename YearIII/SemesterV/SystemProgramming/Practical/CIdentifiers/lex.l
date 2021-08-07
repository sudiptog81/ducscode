%{
    int identifiers = 0;
%}
%%
[#].* { printf("%s <- preprocessor directive\n", yytext); } // preprocessor directives
[ |\n|\t] { ; } // whitespaces
[,|;|"("|")"|"{"|"}"|"\["|"\]"] { ; } // brackets, delimiters
"//".* { printf("%s <- comment\n", yytext); } // single line comment
-?[0-9]+("."[0-9]+)? { printf("%s <- number\n", yytext); } // numbers
void|int|main|char|for|while|continue|switch|case|break|if|else|return|true|false { printf("%s <- keyword\n", yytext); } // keywords
"<="|">="|"!="|"=="|"<"|">" { printf("%s <- relational operator\n", yytext); }  // relational operators
"&"|"|"|"^"|"<<"|">>"|"~" { printf("%s <- bitwise operator\n", yytext); }  // bitwise operators
"&&"|"||"|"!" { printf("%s <- logical operator\n", yytext); } // logical operators
"++"|"--" { printf("%s <- postfix/prefix operator\n", yytext); } // postfix/prefix operators
"="|"+"|"-"|"*"|"/"|"%" { printf("%s <- operator\n", yytext); } // other operators
[']([^\\\']|\\.)?['] { printf("%s <- character\n", yytext); } // characters
["]([^\\\"]|\\.)*["] { printf("%s <- string\n", yytext); } // strings
[A-Za-z_][A-Za-z0-9_]* { identifiers++; printf("%s <- identifier\n", yytext); } // identifiers
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  printf("\nnumber of C identifiers: %d\n", identifiers);
  return 1;
}

int yywrap() {
  return 1;
}
