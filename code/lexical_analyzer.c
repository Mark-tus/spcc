// Design Lexical Analyzer using C/ Java/Python
// Input: HLL
// Output: Collection of tokens
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100
typedef struct {
char token[MAX_LENGTH];
char type[MAX_LENGTH];
} SymbolEntry;
int isKeyword(char* str) {
char keywords[32][10] = {"auto", "break", "case", "char",
"const", "continue", "default","do", "double", "else", "enum",
"extern", "float", "for", "goto","if", "int", "long", "register",
"return", "short", "signed", "sizeof", "static", "struct",
"switch", "typedef", "union", "unsigned", "void", "volatile",
"while"};
for(int i = 0; i < 32; ++i) {
if(strcmp(keywords[i], str) == 0) {
return 1;
}
}
return 0;
}
int isOperator(char ch) {
char operators[] = "+-*/%=><&|^!";
for(int i = 0; operators[i] != '\0'; ++i) {
if(operators[i] == ch) {
return 1;
}
}
return 0;
}
int isIdentifier(char* str) {
if(isalpha(str[0]) || str[0] == '_') {
return 1;
}
return 0;
}
int isConstant(char* str) {
int i = 0;
if(isdigit(str[i])) {
while(isdigit(str[i]))
++i;
if(str[i] == '.')
++i;
while(isdigit(str[i]))
++i;
if(str[i] == 'e' || str[i] == 'E') {
++i;
if(str[i] == '+' || str[i] == '-')
++i;
while(isdigit(str[i]))
++i;
}
if(str[i] == '\0')
return 1;
}
return 0;
}
int main() {
FILE *fp;
char word[MAX_LENGTH];
SymbolEntry symbolTable[MAX_LENGTH];
int symbolCount = 0;
fp = fopen("spcc2.txt", "r");
if (fp == NULL) {
printf("Could not open file.\n");
return 1;
}
while (fscanf(fp, "%s", word) == 1) {
if (isKeyword(word)) {
strcpy(symbolTable[symbolCount].token, word);
strcpy(symbolTable[symbolCount].type, "Keyword");
symbolCount++;
} else if (isOperator(word[0])) {
strcpy(symbolTable[symbolCount].token, word);
strcpy(symbolTable[symbolCount].type, "Operator");
symbolCount++;
} else if (isIdentifier(word)) {
strcpy(symbolTable[symbolCount].token, word);
strcpy(symbolTable[symbolCount].type, "Identifier");
symbolCount++;
} else if (isConstant(word)) {
strcpy(symbolTable[symbolCount].token, word);
strcpy(symbolTable[symbolCount].type, "Constant");
symbolCount++;
} else {
strcpy(symbolTable[symbolCount].token, word);
strcpy(symbolTable[symbolCount].type, "Others");
symbolCount++;
}
}
fclose(fp);
printf("Symbol Table:\n");
printf("%-20s %-20s\n", "Token", "Type");
for(int i = 0; i < symbolCount; i++) {
printf("%-20s %-20s\n", symbolTable[i].token,
symbolTable[i].type);
}
return 0;
}
