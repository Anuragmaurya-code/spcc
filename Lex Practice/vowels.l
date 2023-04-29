%{
    #include<stdio.h>
    int flag;
%}

%%
a|e|i|o|u {
    flag = 1;
    display(flag);
}

.+ {
    flag = 0;
    display(flag);
}
%%

display(int flag){
    if(flag==1)
        printf("[%s] is a vowel", yytext);
    else
        printf("[%s] is not a vowel", yytext);
}

int main(){
    yylex();
}

int yywrap(){
    return 1;
}

