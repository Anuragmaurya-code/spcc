%{
#include<stdio.h>
%}

%%
if |
else | 
printf {printf("\n%s is a keyword", yytext);}
[0-9]+ {printf("\n%s is a number", yytext);}
[a-zA-Z]+ {printf("\n%s is word", yytext);}
. | \n { }
%%

int main(){
    printf("\nEnter the String: ");
    yylex();
}

int yywrap(){
    return 1;
}
