%{
#include<stdio.h>
%}

%%
if|else|printf|goto|return|int|float|double|char {printf("%s is KEYWORD\n", yytext);}
[0-9]+|[0-9]*\.[0-9]+ {printf("%s is NUMBER\n", yytext);}
[a-zA-Z]|[a-zA-Z][a-zA-Z0-9]+ {printf("%s is IDENTIFIER\n", yytext);}
\+|\-|\*|\/|\&&|\^|\!|\<|\> {printf("%s is OPERATOR\n", yytext);}
\"[^\n]*\" {printf("%s is STRING\n", yytext);}
\"|\(|\)|\[|\]|\{|\}|\,|\;|\:|\' {printf("%s is SEPERATOR\n", yytext);}
%%

int main()
{
	while(yylex());
}

int yywrap( )
{
	return 1;
}