#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pm();
void plus();
void divide();

int i, ch, j, l, addr = 100;
char ex[10], expt[10], expt1[10], expt2[10], id1[5], op[5], id2[5];

int main(){
    while (1){
        printf("\n1.Assignment\n2.Arithmetic\n3.Exit\nEnter the choice:");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\nEnter the expression with assignment operator: ");
            scanf("%s", expt);
            l = strlen(expt);
            // expt2[0] = '\0';
            i = 0;
            while (expt[i] != '='){
                i++;
            }
            strncat(expt2, expt, i);
            strrev(expt);
            // expt1[0] = '\0';
            strncat(expt1, expt, l - (i + 1));
            strrev(expt1);
            printf("Three address code:\ntemp=%s\n%s=temp\n", expt1, expt2);
            break;
        case 2:  
            printf("\nEnter the expression with arithmetic operator: ");
            scanf("%s", ex);
            strcpy(expt, ex);
            l = strlen(expt);
            expt1[0] = '\0';
            for (i = 0; i < l; i++){
                if (expt[i] == '+' || expt[i] == '-'){
                    if (expt[i + 2] == '/' || expt[i + 2] == '*'){
                        pm();
                        break;
                    }
                    else{
                        plus();
                        break;
                    }
                }
                else if (expt[i] == '/' || expt[i] == '*'){
                    divide();
                    break;
                }
            }
            break;
        case 3:
            exit(0);
        }
    }
    return 0;
}

void pm()
{
    strrev(expt);
    j = l - i - 1;
    strncat(expt1, expt, j);
    strrev(expt1);
    printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n", expt1, expt[j + 1], expt[j]);
}
void divide()
{
    strncat(expt1, expt, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", expt1, expt[i + 2], expt[i + 3]);
}
void plus()
{
    strncat(expt1, expt, i + 2);
    printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n", expt1, expt[i + 2], expt[i + 3]);
}
