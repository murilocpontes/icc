#include <stdlib.h>
#include <stdio.h>

void main() {
char ch;
printf("\nDigite um caracter (digite s para sair): ");
while (ch!= 's') {
printf("\nO caracter digitado e %c", ch);
printf("\n Digite outro caracter (digite s para sair): ");
ch=getchar();
}
printf("\nSaindo do loop\n");
}
