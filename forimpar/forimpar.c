#include <stdlib.h>
#include <stdio.h>
int main () {
    int n1, n2, cont, soma;
    soma = 0;
    printf ("SOMA DOS IMPARES NUM INTERVALO NUMERICO!!!\n\n");
    printf("Insira um intervalo numerico crescente\n");
    scanf("%d",&n1);
    scanf("%d", &n2);
    cont = n1;
    if ( n1 >= n2) {
        printf("Intervalo de valores invalido\n");
        return 0;
    }
    else {
        for (cont;cont <= n2; cont++) {
            if ((cont % 2) !=0) 
                soma = soma + cont;
        }
        printf("A soma dos numeros impares existentes no intervalo de %d a %d eh %d\n", n1, n2, soma);
        return 0;
    }
}