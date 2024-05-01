// Assemblers : Pass2 of Assembler .
// Input: Assembly language program, MOT, POT, ST
// Output: M/C code
// Input
// PG1 START 0
// ** USING *,15
// ** L 1,FIVE
// ** A 1,FOUR
// ** ST 1,TEMP
// FIVE DC F'5'
// FOUR DC F'4'
// TEMP DS 1F
// ** END PG1
// MOT
// A 5A
// L 6A
// ST 7A
// END
// POT
// DS
// DC
// START
// USING
// ST
// FIVE 12
// FOUR 16
// TEMP 20
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function to convert opcode to machine code
char* convertToMachineCode(char* opcode) {
if (strcmp(opcode, "A") == 0) return "5A";
else if (strcmp(opcode, "L") == 0) return "6A";
else if (strcmp(opcode, "ST") == 0) return "7A";
else return "00"; // Default for unknown opcodes
}
int main() {
char label[10], opcode[10], operand[10], mnemonic[10];
int locctr = 0;
FILE *fp1, *fp2, *fp3, *fp4, *fp5; // Input: Assembly, MOT, POT, ST; Output: M/C Code
fp1 = fopen("input.txt", "r");
fp2 = fopen("MOT.txt", "r");
fp3 = fopen("POT.txt", "r");
fp4 = fopen("ST.txt", "r");
fp5 = fopen("machine_code.txt", "w"); // Output file for machine code
fscanf(fp1, "%s %s %s", label, opcode, operand); // Read the first line
while (strcmp(opcode, "END") != 0) {
int found = 0;
// Check if the opcode is in MOT
rewind(fp2);
while (fscanf(fp2, "%s", mnemonic) == 1) {
if (strcmp(opcode, mnemonic) == 0) {
found = 1;
break;
}
}
if (found) {
char* machineCode = convertToMachineCode(opcode);
fprintf(fp5, "%d: %s\n", locctr, machineCode);
locctr += 4; // Increment locctr by 4 for each instruction
}
fscanf(fp1, "%s %s %s", label, opcode, operand);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
fclose(fp4);
fclose(fp5);
return 0;
}
