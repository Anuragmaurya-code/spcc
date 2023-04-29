%{
   #include<stdio.h> 
%}
%%
if |
else |
printf {printf("%s is a keyword\n",yytext);}

[0-9]+ {printf("%s is a number\n",yytext);}
[a-zA-Z]+ {printf("%s is a word\n",yytext);}

%%
main(){
  printf("Enter input string\n");
  yylex(); 
}
yywrap(){
    return 1;      
  }    
   
