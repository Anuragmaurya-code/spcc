%{
 #include<stdio.h>
 int m;
%}

%%
[0-9]+ {m=atoi(yytext);
			if(m%2==0){
				printf("%d is even number\n",m);
			}
			else{
				printf("%d is odd number\n",m);
			}
			}

%%
main(){
printf("Enter the number:\n");
yylex();

}
yywrap(){
return 1;
}
