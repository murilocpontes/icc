#include <stdlib.h>
#include <stdio.h>

#define TAMMAX 15

int main () {
    int n, i, j, flag;
    int matriz1 [TAMMAX] [TAMMAX];
    int matriz2 [TAMMAX] [TAMMAX];
    int resultriz [TAMMAX] [TAMMAX];
    printf("Digite o tamanho das matrizes:\n");
    scanf ("%d", &n);
    for (i=0; i<n; i++) {
        printf("Linha %d:\n", i+1);
        for (j=0; j<n;j++) {
            printf("Coluna %d:\n", j+1);
            printf("Digite o valor desejado para a posição:");
            scanf("%d", &matriz1 [j] [i]);
        }
    }
    for (i=0;i<n;i++) {
        for (j=0; j<n; j++) {
            if (j !=(n-1)) 
                printf("%d\t", matriz1 [j] [i]);
            else
                printf("%d\n", matriz1 [j] [i]);
        }
    }

    printf("Matriz 2:\n\n");
    for (i=0; i<n; i++) {
        printf("Linha %d:\n", i+1);
        for (j=0; j<n;j++) {
            printf("Coluna %d:\n", j+1);
            printf("Digite o valor desejado para a posição:");
            scanf("%d", &matriz2 [j] [i]);
        }
    }
    for (i=0;i<n;i++) {
        for (j=0; j<n; j++) {
            if (j !=(n-1)) 
                printf("%d\t", matriz2 [j] [i]);
            else
                printf("%d\n", matriz2 [j] [i]);
        }
    }
    printf ("Escolha sua operação:\n");
    printf ("(0) Soma\n(1) Subtracao\n");
    scanf("%d", &flag);
    switch (flag) {
        case 0: 
        for (i=0;i<n;i++) {
        for (j=0; j<n; j++) 
            resultriz [j] [i] = matriz1 [j] [i] + matriz2 [j] [i];   
        } break;
        case 1:
        for (i=0;i<n;i++) {
        for (j=0; j<n; j++) 
            resultriz [j] [i] = matriz1 [j] [i] - matriz2 [j] [i];
        } break;
        default:
        printf("Erro!\n");
        break;
    }
    for (i=0;i<n;i++) {
        for (j=0; j<n; j++) {
            if (j !=(n-1)) 
                printf("%d\t", resultriz [j] [i]);
            else
                printf("%d\n", resultriz [j] [i]);
        }
    }
    

return 0;
}