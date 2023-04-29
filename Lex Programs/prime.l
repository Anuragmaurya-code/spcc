%{
#include<stdio.h>
int flag=0,i,temp;
%}
%%
[0-9]+ {
flag = 0;
temp=atoi(yytext);
if(temp==0 || temp==1){
flag=1;
}
for(i=2;i<=temp/2;++i){
if(temp%i==0){
flag=1;
break;
}
}
if(flag==1){
printf("%d is not a prime number\n",temp);
}
else{
printf("%d is  a prime number\n",temp);
}
}
%%

int main(){
printf("Enter the number:\n");
yylex();
}
int yywrap(){
return 1;
}
