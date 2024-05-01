// Macroprocessor : Pass2 Macro processor.
// Input: Assembly language program with Macro, MNT, MDT
// Output: Expanded source code
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
// END
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 100
#define MAX_LENGTH 100
typedef struct {
char macro_name[MAX_LENGTH];
int mdt_index;
} MNTEntry;
int main() {
FILE *macro_file, *mnt_file, *mdt_file, *input_file, *output_file;
char input_line[MAX_LENGTH], expanded_line[MAX_LINES][MAX_LENGTH];
MNTEntry mnt[MAX_LINES];
char mdt[MAX_LINES][MAX_LENGTH];
// Open files
macro_file = fopen("macro.txt", "r");
mnt_file = fopen("mnt.txt", "r");
mdt_file = fopen("mdt.txt", "r");
input_file = fopen("input.txt", "r");
output_file = fopen("output.txt", "w");
// Read MNT entries
int mnt_count = 0;
while (fscanf(mnt_file, "%s %d", mnt[mnt_count].macro_name,
&mnt[mnt_count].mdt_index) == 2) {
mnt_count++;
}
// Read MDT lines
int mdt_count = 0;
while (fgets(mdt[mdt_count], MAX_LENGTH, mdt_file) != NULL) {
mdt_count++;
}
// Expand macros in input file
while (fgets(input_line, MAX_LENGTH, input_file) != NULL) {
int i;
for (i = 0; i < mnt_count; i++) {
if (strstr(input_line, mnt[i].macro_name) != NULL) {
int index = mnt[i].mdt_index;
while (strcmp(mdt[index], "MEND\n") != 0) {
strcpy(expanded_line[i], mdt[index]);
index++;
}
}
}
fprintf(output_file, "%s", input_line);
}
// Close files
fclose(macro_file);
fclose(mnt_file);
fclose(mdt_file);
fclose(input_file);
fclose(output_file);
return 0;
}
