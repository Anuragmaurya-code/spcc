%{
  #include<stdio.h>
  int counter=0;
 
%}

%%
[a-zA-Z]+ {
if(yyleng >counter){
counter=yyleng;

}
}
%%
main(){
printf("Enter the sentence\n");
yylex();
printf("The largest word length is :%d\n",counter);

}
yywrap(){
return 1;
}
