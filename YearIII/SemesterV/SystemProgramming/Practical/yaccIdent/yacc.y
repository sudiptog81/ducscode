/* yacc.y */
%{
  #include <stdio.h>
  #include <stdlib.h>
  extern int yylex();
  void yyerror(char *);
%}

%token D L
%%
S : L D { printf("VALID IDENTIFIER\n"); }
  ;
%%
int main()
{
    yyparse();
    return 0;
}

void yyerror(char *msg)
{
    fprintf(stderr, "INVALID IDENTIFIER\n");
    exit(1);
}
