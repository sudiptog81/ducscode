/* yacc.y */
%{
  #include <stdio.h>
  #include <stdlib.h>
  extern int yylex();
  void yyerror(char *);
%}

%token A B

%%
S : E '\n' { printf("VALID STRING\n"); exit(0); }
  ;
E : A E B
  | A B
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
