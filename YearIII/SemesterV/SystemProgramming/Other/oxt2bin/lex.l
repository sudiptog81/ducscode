%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    int valid, octal, decimal, binary;
%}
%%
[0-7]+ { valid = 1; octal = atoi(yytext); }
[ \n\t] { ; }
. { printf("INVALID\n"); return 0; }
%%
int oct2dec(int oct)
{
    int dec = 0;
    for (int i = 0; i < 2; i++)
    {
        dec += (oct % 10) * pow(8, i);
        oct /= 10;
    }
    return dec;
}

int dec2bin(int dec)
{
    int bin = 0;
    for (int i = 0; i < 8; i++)
    {
        bin += (dec % 2) * pow(10, i);
        dec /= 2;
    }
    return bin;
}

int yywrap()
{
    if (valid)
    {
      decimal = oct2dec(octal);
      binary = dec2bin(decimal);
      printf("BINARY: %d\n", binary, octal);
    }
    return 0;
}

int main()
{
    printf("OCTAL: ");
    yylex();
    return 0;
}
