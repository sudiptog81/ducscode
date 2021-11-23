/* yacc.y */
%{
  #include <stdio.h>
  #include <stdlib.h>
  extern int yylex();
  void yyerror(char *);
%}

%token A B
%%
S : X Y B { printf("VALID STRING\n"); } 
  ;
X : A A A A A A A A A A
  ;
Y : A Y
  |
  ;
%%
int main()
{
   yyparse();
   return 0;
}

void yyerror(char *msg) {
  fprintf(stderr, "INVALID STRING\n");
  exit(1);
}

