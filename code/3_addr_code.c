// Write program to generate three address code for given assignment, arithmetic
// and relational statement
#include <stdio.h>
#include <string.h>
int main() {
printf("Intermediate Code Generation:\n\n");
while (1) {
printf("1. Assignment 2. Arithmetic 3. Relational 4. Exit\n");
int choice;
scanf("%d", &choice);
if (choice == 1) {
char expr[100];
printf("Enter the assignment expression: ");
scanf("%s", expr);
char *a1 = strtok(expr, "=");
char *a2 = strtok(NULL, "=");
printf("temp = %s\n", a2);
printf("%s = temp\n", a1);
}
else if (choice == 2) {
char expr[100];
printf("Enter the arithmetic expression: ");
scanf("%s", expr);
char var[50], rhs[50], op;
sscanf(expr, "%[^=]=%s", var, rhs);
char *a_op = "+-*/^%";
char *ptr = strpbrk(rhs, a_op);
if (ptr == NULL) {
printf("Invalid arithmetic expression\n");
continue;
}
op = *ptr;
char operand1[50], operand2[50];
sscanf(rhs, "%[^+-*/^%%]%*c%s", operand1, operand2);
printf("temp = %s %c %s\n", operand1, op, operand2);
printf("%s = temp\n", var);
}
else if (choice == 3) {
char expr[100];
printf("Enter the relational expression: ");
scanf("%s", expr);
char var1[50], var2[50], rel_op[3];
sscanf(expr, "%s %s %s", var1, rel_op, var2);
printf("if (%s %s %s) goto L1\n", var1, rel_op, var2);
printf("t = 0\n");
printf("goto L2\n");
printf("t = 1\n");
}
else if (choice == 4) {
break;
}
else {
printf("Invalid choice\n");
}
}
return 0;
}
