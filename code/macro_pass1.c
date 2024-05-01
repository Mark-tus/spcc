// (* /* Macroprocessor : pass1 Macro processor.
// Input: Assembly language program with Macro, Output: MNT,
// MDT
// Input1:
// MACRO
// INCR
// AR 2,3
// MR 1,2
// ST 1,2
// MEND
// PG1 START
// USING *,15
// L 1,FIVE
// A 1, FOUR
// INCR
// ST 1,TEMP
// M 1,FIVE
// INCR
// FIVE DC F’5’
// FOUR DC F’4’
// TEMP DS 1F
// END */ *)
#include <stdio.h>
#include <string.h>
int main() {
FILE *inputFile, *mntFile, *mdtFile;
char label[10], opcode[10], operand[10], macro[10];
// Open input file
inputFile = fopen("input.txt", "r");
if (inputFile == NULL) {
printf("Error opening input file.\n");
return 1;
}
// Open MNT file
mntFile = fopen("mnt.txt", "w");
if (mntFile == NULL) {
printf("Error creating MNT file.\n");
fclose(inputFile);
return 1;
}
// Open MDT file
mdtFile = fopen("mdt.txt", "w");
if (mdtFile == NULL) {
printf("Error creating MDT file.\n");
fclose(inputFile);
fclose(mntFile);
return 1;
}
// Read the input file line by line
while (fscanf(inputFile, "%s", opcode) != EOF) {
// Check if opcode is MACRO
if (strcmp(opcode, "MACRO") == 0) {
// Read macro name
fscanf(inputFile, "%s", macro);
fprintf(mntFile, "%s %d\n", macro, ftell(mdtFile));
fprintf(mdtFile, "%s ", macro);
// Read and write macro parameters to MDT
fscanf(inputFile, "%s", opcode);
while (strcmp(opcode, "MEND") != 0) {
fprintf(mdtFile, "%s ", opcode);
fscanf(inputFile, "%s", opcode);
}
fprintf(mdtFile, "%s\n", opcode);
}
}
// Close all files
fclose(inputFile);
fclose(mntFile);
fclose(mdtFile);
printf("Macro Pass 1 completed successfully.\n");
return 0;
}
