%{
    int identifiers = 0;
%}
%%
[#].* { printf("%s <- preprocessor directive\n", yytext); } // preprocessor directives
[ |\n|\t] { ; } // whitespaces
[,|;|"("|")"|"{"|"}"|"\["|"\]"] { ; } // brackets, delimiters
"//".* { printf("%s <- comment\n", yytext); } // single line comments
-?[0-9]+ { printf("%s <- integer\n", yytext); } // integers
-?[0-9]+("."[0-9]+) { printf("%s <- float\n", yytext); } // floats
void|int|main|char|for|while|continue|switch|case|break|if|else|return|true|false { printf("%s <- keyword\n", yytext); } // keywords
"<="|">="|"!="|"=="|"<"|">"|"&"|"|"|"^"|"<<"|">>"|"~"|"&&"|"||"|"!"|"++"|"--"|"="|"+"|"-"|"*"|"/"|"%" { printf("%s <- operator\n", yytext); } // operators
[']([^\\\']|\\.)?['] { ; } // characters
["]([^\\\"]|\\.)*["] { ; } // strings
[a-zA-Z_]+[a-zA-Z0-9_]* { identifiers++; printf("%s <- identifier\n", yytext); } // identifiers
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  return 0;
}

int yywrap() {
  return 1;
}
