%{
#include<stdio.h>
int count=0;
%}

%%
[a-zA-Z]+ {
    if(yyleng>count){
        count = yyleng;
    }
}

\n {
    printf("The length of largest word is %d",count);
    count = 0;
    printf("\nEnter a Sentence: \n");
}
%%

int main(){
    printf("Enter a Sentence: \n");
    yylex();
}

int yywrap(){
    return 1;
}