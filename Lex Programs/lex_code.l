%{
#include<stdio.h>
%}

%%
[\t ]+ ;
[0-9]+|[0-9]*\.[0-9]+ { printf("%s is NUMBER\n", yytext);}
\/\/.*|\/\*[^\n]*\*\/ { printf("%s is COMMENT\n", yytext);}
if|else|while|for|switch|goto|elif|NULL|printf { printf("%s is KEYWORD\n", yytext);}
\+|\-|\*|\/|\==|\&&|\!|\= { printf("%s is OPERATOR\n", yytext);}
[a-zA-Z]|[a-zA-Z][a-zA-Z0-9]+ { printf("%s is IDENTIFIER\n", yytext);}
\,|\;|\(|\)|\{|\}|\[|\] {printf("%s is SEPERATOR\n", yytext);}
\"[^\"\n]*\" { printf("%s is STRING\n", yytext);}
\n { ECHO;}
%%

int main()
{
	while(yylex());
}

int yywrap( )
{
	return 1;
}