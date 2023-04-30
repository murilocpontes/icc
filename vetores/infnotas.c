#include <stdlib.h>
#include <stdio.h>
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main () {
    int i=0;
    float *nota = (float*) malloc (sizeof(float));
    float media=0, soma=0;
    char flag = 's';

    do {
        printf("Digite a nota %d:\n", i+1);
        scanf("%f", nota+((i+1)*sizeof(float)));

        if (*(nota+(i+1)*sizeof(float))> 10.00 || *(nota+(i+1)*sizeof(float))<0.00) {
            printf("Nota invalida!!!\n");
            continue;
        }
        else {
            soma+= *(nota+(i+1)*sizeof(float));
            printf ("%.2f\n", nota[i]);
            printf ("%.2f\n", soma);
            printf ("%.2f\n", *(nota+(i+1)*sizeof(float)));
            i++;
            while (flag == 's') {
                printf ("Deseja inserir mais notas? (s/n)\n");
                clearInputBuffer();
                flag = getchar();
                if (flag != 's' && flag != 'n') 
                    printf("Opcao invalida\n");
                else {
                    if (flag == 's') {
                        nota = realloc (nota, (i+1) * sizeof(float));
                        break;
                    }
                }
           }
        }
    } while (flag == 's');

    media= soma/((float)i);
    printf("A media dos alunos foi: %.2f\n", media);
    return 0;
}
