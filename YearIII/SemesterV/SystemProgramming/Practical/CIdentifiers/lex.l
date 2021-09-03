%{
    int identifiers = 0;
%}
%%
[#].* { ; } // preprocessor directives
[ |\n|\t] { ; } // whitespaces
[,|;|"("|")"|"{"|"}"|"\["|"\]"] { ; } // brackets, delimiters
"//".* { ; } // single line comment
-?[0-9]+("."[0-9]+)? { ; } // numbers
void|int|main|char|for|while|continue|switch|case|break|if|else|return|true|false { ; } // keywords
"<="|">="|"!="|"=="|"<"|">" { ; }  // relational operators
"&"|"|"|"^"|"<<"|">>"|"~" { ; }  // bitwise operators
"&&"|"||"|"!" { ; } // logical operators
"++"|"--" { ; } // postfix/prefix operators
"="|"+"|"-"|"*"|"/"|"%" { ; } // other operators
[']([^\\\']|\\.)?['] { ; } // characters
["]([^\\\"]|\\.)*["] { ; } // strings
[A-Za-z_][A-Za-z0-9_]* { identifiers++; printf("%s <- identifier\n", yytext); } // identifiers
%%
int main() {
  yyin = fopen("text.c", "r");
  yylex();
  printf("\nnumber of C identifiers: %d\n", identifiers);
  return 0;
}

int yywrap() {
  return 1;
}
