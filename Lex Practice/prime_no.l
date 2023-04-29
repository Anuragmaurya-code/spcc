%{
    #include<stdio.h>
    int n, flag = 0, i;
%}

%%
[0-9]+ {
    flag = 0;
    n = atoi(yytext);
    if (n==0 || n==1){
        flag=1;
    }
    for(i=2;i<=n/2;++i){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("%d is not a prime number", n);
    }
    else{
        printf("%d is a prime number", n);
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