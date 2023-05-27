#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    int Id_Aluno;
    int Nota_Aluno;
} tipo_aluno;
tipo_aluno aluno[10];
int maior[2];
int contador[3];

void inicializa(){
    int i;
    for(i=0;i<10;i++){
    aluno[i].Nota_Aluno = 0;
    aluno[i].Id_Aluno = 0;  
    }
    for(i=0;i<2;i++){
        maior[i] = 0;
        contador[i] = 0;
    }
}

int main(){
    srand(time(NULL));
    int i, j;

    inicializa();
    for(i=0;i<10;i++){
        aluno[i].Nota_Aluno = rand()%11;
        aluno[i].Id_Aluno = i+1;

        printf("Aluno %d -> Nota %d\n", aluno[i].Id_Aluno, aluno[i].Nota_Aluno);
        if(aluno[i].Nota_Aluno > maior[2]) {
            maior[1] = aluno[i].Id_Aluno;
            maior[2] = aluno[i].Nota_Aluno;
        }
    }
    for(i=0;i<10;i++){
        for(j=0;j<10;j++) {
            if (aluno[i].Nota_Aluno == aluno[j].Nota_Aluno) 
                contador[2]++;
        }
        if(contador[2]>contador[1]) {
            contador[1]=contador[2];
            contador[3]=aluno[i].Nota_Aluno;
        }
        contador[2]=0;
    }
    printf("A maior nota foi do aluno %d: %d\n", maior[1],maior[2]);
    printf("A nota %d ocorreu %d vezes\n",contador[3],contador[1]);
}