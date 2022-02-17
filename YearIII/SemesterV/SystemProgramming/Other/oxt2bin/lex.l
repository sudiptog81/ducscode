%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <math.h>
    char *hex;
    int valid, hexlen, decimal, binary, value;
%}
%%
0x[0-9a-fA-F]+ { valid = 1; hex = yytext; hexlen = yyleng; }
[ \n\t] { ; }
. { printf("INVALID\n"); return 0; }
%%
int hex2dec(char *hex, int hexlen)
{
    int dec = 0;
    hexlen = hexlen - 3;
    for(int i = 2; hex[i] != '\0'; i++)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
            value = hex[i] - 48;
        else if(hex[i] >= 'a' && hex[i] <= 'f')
            value = hex[i] - 97 + 10;
        else if(hex[i] >= 'A' && hex[i] <= 'F')
            value = hex[i] - 65 + 10;

        dec += value * pow(16, hexlen);
        hexlen--;
    }
    return dec;
}

int dec2bin(int dec)
{
    int bin = 0;
    for (int i = 0; i < 16; i++)
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
      decimal = hex2dec(hex, hexlen);
      binary = dec2bin(decimal);
      fprintf(yyout, "%d\n", binary);
    }
    return 0;
}

int main()
{
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    return 0;
}
