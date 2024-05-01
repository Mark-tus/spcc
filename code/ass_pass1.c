/*Assemblers : Pass1 of Assembler .
Input: Assembly language program, MOT,POT
Output: Symbol table
Input
PG1 START 0
** USING *,15
** L 1,FIVE
** A 1,FOUR
** ST 1,TEMP
FIVE DC F'5'
FOUR DC F'4'
TEMP DS 1F
** END PG1
MOT
A 5A
L 6A
ST 7A
END
POT
DS
DC
START
USING*/
//code -
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
char label[10], opcode[10], operand[10], mnemonic[10];
int locctr = 0;
FILE *fp1, *fp2, *fp3, *fp4, *potFile;
fp1 = fopen("input.txt", "r"); // input
fp2 = fopen("mot.txt", "r"); // input
fp3 = fopen("output.txt", "w"); // output
fp4 = fopen("st.txt", "w"); // output
potFile = fopen("pot.txt", "r"); // pseudo-operation table
fscanf(fp1, "%s %s %s", label, opcode, operand); // Read the first line
printf("%d %s %s %s\n", locctr, label, opcode, operand);
fprintf(fp3, "%d %s %s %s\n", locctr, label, opcode, operand);
while (strcmp(opcode, "END") != 0)
{
//POT MAI CHECK KIYA
int isPseudoOp = 0;
rewind(potFile);
while(fscanf(potFile,"%s",mnemonic)==1){
if(strcmp(opcode,mnemonic)==0){
isPseudoOp = 1;
break;
}
}
if (isPseudoOp)
{
// Handle pseudo-operation
// printf("Pseudo-op: %s\n", opcode);
// fprintf(fp3, "%d %s %s %s\n", locctr, label, opcode, operand);
// Do not increment locctr for pseudo-operations
if (strcmp(opcode, "DC") == 0 || strcmp(opcode, "DS") == 0)
{
printf("%s %d\n", label, locctr);
fprintf(fp4, "%s %d\n", label, locctr);
printf("%d %s %s %s\n", locctr, label, opcode, operand);
locctr += 4;
}
}
if (strcmp(opcode, "DC") != 0 && strcmp(opcode, "DS") != 0)
{
fscanf(fp2, "%s", mnemonic);
printf("%d %s %s %s\n", locctr, label, opcode, operand);
fprintf(fp3, "%d %s %s %s\n", locctr, label, opcode, operand);
while (strcmp(mnemonic, "end") != 0)
{
if (strcmp(opcode, mnemonic) == 0)
{
locctr += 4;
break;
}
fscanf(fp2, "%s", mnemonic);
}
rewind(fp2);
}
fscanf(fp1, "%s %s %s", label, opcode, operand);
}
printf("%d %s %s %s\n", locctr, label, opcode, operand);
fprintf(fp3, "%d %s %s %s\n", locctr, label, opcode, operand);
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
return 0;
}
