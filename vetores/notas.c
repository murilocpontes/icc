#include <stdlib.h>
#include <stdio.h> 

int main () {
    float notas [10], maior [2], menor [2]; // maior[1] e menor[1] pra contagem crescente, maior [2] e menor [2] para contagem decrescente
    int i, j, k[4] , en_nota; // k[1] e k[2] maior, k[3] e k[4] menor
    float soma, media;
    en_nota = 1;
    soma = 0.00;
    for (i=0; i< 10; i++) {
        printf("Insira a nota %d:\n", en_nota);
        scanf ("%f", &notas[i]);
        if (notas[i] < 0.00 || notas[i] > 10.00) {
            printf("Nota invalida!!\n");
            i=-1;
            en_nota = 1;
            soma = 0;
        }
        else {
            soma = soma + notas[i];
            en_nota = en_nota + 1;
        }
    }
    printf("> Lendo de tras pra frente:\n");
    for (i=9;i>=0; i--) { //contagem decrescente
        printf("%.2f\n", notas[i]); 
        for (j=9; j>=0; j--) {
            if (notas[i]>notas[j]) {
                maior [2] = notas [i];
                k[2]=i;
            }
            else {
                menor [2] = notas [i];
                k[4] = i;
            }
        }
       
    }
    for (i=0; i<10;i++) { //contagem crescente
        for (j=0;j<10; j++) {
            if (notas[i]>notas[j]) {
                maior [1] = notas[i];
                k[1] = i;
            }
            else {
                menor [1] = notas[i];
                k[3] = i;
            }
        }
    }
    if (maior[1]>=maior[2])
        printf ("> Maior valor: Nota [%d] = %.2f\n", k[1], maior[1]);
    else
        printf ("> Maior valor: Nota [%d] = %.2f\n", k[2], maior[2]);
    if (menor[1]<=menor[2])
        printf ("> Menor valor: Nota [%d] = %.2f\n", k[3], menor[1]);
    else
        printf ("> Menor valor: Nota [%d] = %.2f\n", k[4], menor[2]);
    media = soma /(float)en_nota;
    printf ("> Media das notas: %.2f\n", media);
    return 0;
}