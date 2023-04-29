%{
    #include<stdio.h>
    int m;
%}

%%
[0-9]+ {
    m = atoi(yytext);
    if (m%2==0){
        printf("%d is an even no.\n", m);
    }
    else{
        printf("%d is an odd no.\n", m);
    }
}
%%

int main(){
    printf("Enter a Number: ");
    yylex();
}

int yywrap(){
    return 1;
}