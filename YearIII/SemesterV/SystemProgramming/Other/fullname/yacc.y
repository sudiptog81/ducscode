/* yacc.y */
%{
  #include <stdio.h>
  #include <stdlib.h>
  extern int yylex();
  void yyerror(char *);
%}

%token NAME
%%
S : NAME ' ' NAME '\n' { printf("VALID NAME\n"); }
  ;
%%
int main()
{
    yyparse();
    return 0;
}

void yyerror(char *msg)
{
    fprintf(stderr, "INVALID NAME\n");
    exit(1);
}
