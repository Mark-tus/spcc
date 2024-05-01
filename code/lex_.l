// Write a Lex program for
// (1) Count number of newlines, spaces and words
%{
#include <stdio.h>
int chars = 0, word = 0, newLine = 0, space = 0;
%}
%%
[a-zA-Z]{1} {chars++;}
[a-zA-Z]{2,} {word++;}
[ ] {space++;}
[\n] {newLine++;}
%%
int yywrap(){
return 1;
}
int main()
{
printf("Enter String: ");
yylex();
printf("Number of characters is: %d\n", chars);
printf("Number of words is: %d\n", word);
printf("Number of spaces is: %d\n", space);
printf("Number of new line characters is: %d\n", newLine);
}

// (2) Count number of operators and operands
%{
#include <stdio.h>
int operator=0,operand=0;
%}
%%
[+\-\*\/\%^] {operator++;}
[a-zA-Z0-9]+ {operand++;}
%%
int yywrap(){
return 1;
}
int main(){
printf("Enter the string:");
yylex();
printf("Operators: %d \nOperands: %d\n",operator,operand);
return 0;
}

// (3) Count tokens – identifiers, constants, operators, special symbols
%{
#include <stdio.h>
int keyword=0;
int operator=0;
int special=0;
int identifier=0;
%}
%%
[int||char||float||return||if||else||do||while] {keyword++;}
[=+\-\*\/^] {operator++;}
[a-zA-Z0-9]+ {identifier++;}
[%/&/$/;] {special++;}
%%
int yywrap(){
return 1;
}
int main(){
printf("Enter the code:");
yylex();
printf("Keyword: %d \nOperators: %d \nIdentifier: %d \nSpecial symbols:
%d",keyword,operator,identifier,special);
return 0;
}

// (4) Count number of vowels and Consonants
%{
#include <stdio.h>
int vow=0,con=0;
%}
%%
[aeiouAEIOU] {vow++;}
[a-zA-Z] {con++;}
%%
int yywrap(){
return 1;
}
int main(){
printf("Enter the string:");
yylex();
printf("Vowels: %d \nConsonants: %d\n",vow,con);
return 0;
}

// (5) Count positive and negative integer and fractions
%{
#include <stdio.h>
int pos_int = 0,pos_frac = 0;
int neg_int = 0,neg_frac = 0;
%}
%%
[+]?[0-9]* {pos_int++;}
[+]?[0-9]*\.[0-9]+ {pos_frac++;}
[-][0-9]* {neg_int++;}
[-][0-9]*\.[0-9]+ {neg_frac++;}
%%
int yywrap(){
return 1;
}
int main(){
printf("Enter the number:\n");
yylex();
printf("Positive Integer: %d\n",pos_int);
printf("Positive Fraction: %d\n",pos_frac);
printf("Negative Integer: %d\n",neg_int);
printf("Negative Fraction: %d\n",neg_frac);
return 0;
}
