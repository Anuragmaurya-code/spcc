// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// void main()
// {

//     FILE *fint, *flen, *fsym, *ftab;
//     char start[10], add[10], label[10], operand[10], opcode[10], code[10], mnemonic[10], symadd[10], symlab[10];
//     int len;

//     fint = fopen("input.txt", "r");
//     ftab = fopen("optab.txt", "r");
//     flen = fopen("length.txt", "r");
//     fsym = fopen("symbol.txt", "r");

//     fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);
//     if (strcmp(opcode, "START") == 0)
//     {
//         strcpy(start, operand);
//         fscanf(flen, "%d", &len);
//     }
//     printf("H^%s^%s^%d\nL^00%s^", label, start, len, start);
//     fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);

//     while (strcmp(opcode, "END") != 0)
//     {
//         fscanf(ftab, "%s\t%s", code, mnemonic);
//         while (!feof(ftab))
//         {
//             if (strcmp(opcode, code) == 0)
//             {
//                 fclose(ftab);
//                 fscanf(fsym, "%s\t%s", symadd, symlab);
//                 while (!feof(fsym))
//                 {
//                     if (strcmp(operand, symlab) == 0)
//                     {
//                         printf("%s%s^", mnemonic, symadd);
//                         break;
//                     }
//                     fscanf(fsym, "%s\t%s", symadd, symlab);
//                 }
//                 break;
//             }
//             fscanf(ftab, "%s\t%s", code, mnemonic);
//         }

//         if ((strcmp(opcode, "WORD") == 0) || (strcmp(opcode, "BYTE") == 0))
//         {
//             if (strcmp(opcode, "WORD") == 0)
//             {
//                 printf("0000%s", operand);
//             }
//             else
//             {
//                 int length = strlen(operand);
//                 for (int i = 2; i < length; i++)
//                 {
//                     printf("%d", operand[i]);
//                 }
//                 printf("^");
//             }
//         }
//         fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);
//         ftab = fopen("optab.txt", "r");
//         fseek(ftab, SEEK_SET, 0);
//     }
//     printf("\nE^00%s", start);
//     fclose(fint);
//     fclose(flen);
//     fclose(fsym);
//     fclose(ftab);
// }

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char add[10], label[10], opcode[10], operand[10], sym[10], symval[10], start[10], code[10], mnemonic[10];
    int len;

    FILE *fint, *fopt, *fsym, *flen;
    fint = fopen("input.txt", "r");
    fopt = fopen("optab.txt", "r");
    fsym = fopen("symbol.txt", "r");
    flen = fopen("length.txt", "r");

    fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);
    if(strcmp(opcode,"START")==0){
        strcpy(start, operand);
        fscanf(flen, "%d", &len);
        printf("H^%s^%s^%d\nL^00%s^", label, start, len, start);
    }

    fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);
    while(strcmp(opcode,"END")!=0){
        fscanf(fopt, "%s\t%s", code, mnemonic);
        while(!feof(fopt)){
            if(strcmp(opcode, code)==0){
                fclose(fopt);
                fscanf(fsym, "%s\t%s", symval, sym);
                while(!feof(fsym)){
                    if(strcmp(sym, operand)==0){
                        printf("%s%s^",mnemonic,symval);
                        break;
                    }
                    fscanf(fsym, "%s\t%s", sym, symval);
                }
                break;
            }
            fscanf(fopt, "%s\t%s", code, mnemonic);
        }

        if(strcmp(opcode, "WORD")==0 || strcmp(opcode, "BYTE")==0){
            if(strcmp(opcode, "WORD")==0){
                printf("0000%s", operand);
            }
            else{
                int length = strlen(operand);
                for(int i=2;i<length;i++){
                    printf("%d", operand[i]);
                }
                printf("^");
            }
        }

    fscanf(fint, "%s\t%s\t%s\t%s", add, label, opcode, operand);
        fopen("./optab.txt", "r");
        fseek(fopt, SEEK_SET, 0);
    }
    printf("\nE^%s", start);
    fclose(fint);
    fclose(fopt);
    fclose(fsym);
    fclose(flen);
}