%{
  #include <stdio.h>
  #include <stdlib.h>
%}
%%
[sS][eE][lL][eE][cC][tT] {printf("SELECT => KEYWORD\n"); }
[fF][rR][oO][mM] {printf("FROM => KEYWORD\n");  }
[wW][hH][eE][eR][eE] {printf("WHERE => KEYWORD\n"); }
[a-zA-Z]([a-zA-Z]|[0-9])* { printf("%s => ID\n", yytext); }	
[ |\t|\n] { ; }
. { ; }
%%
int yywrap()
{
  return 1;
}

int main()
{
  yyin = fopen("test.sql", "r");
	yylex();
	return 0;
}
