#include <stdlib.h>
#include <stdio.h>

FILE *Arq;

typedef struct{
    float n1, n2, media;
    int num;
    char nome[64];
    int aprov;
} tipo_aluno;

void turma_info(int *qnt_aluno, float *media_ref, float *peso_p1, float *peso_p2){

    printf("> Definir informacoes da Turma <\n");
    printf("Digite o total de alunos na turma:");
    scanf("%d", qnt_aluno);
    printf("\nDigite a media de aprovacao:");
    scanf("%f",media_ref);
    printf("\nDigite o peso da Nota1:");
    scanf("%f",peso_p1);
    printf("\nDigite o peso da Nota2:");
    scanf("%f",peso_p2);
}

void inserir_aluno(tipo_aluno *alunos, int i, float peso1, float peso2, float media_ref){
    printf("> Inserir aluno e notas <\n");
    printf("Entre com o nro. do aluno:");
    scanf("%d",&alunos[i].num);
    fflush(stdin);

    printf("\nEntre com o nome do aluno:");
    scanf("%s",alunos[i].nome);
    fflush(stdin);

    printf("\nEntre com a Nota1 do aluno:");
    scanf("%f",&alunos[i].n1);
    fflush(stdin);

    printf("\nEntre com a Nota2 do aluno:");
    scanf("%f",&alunos[i].n2);
    fflush(stdin);
    
    alunos[i].media = ((peso1*alunos[i].n1) + (peso2*alunos[i].n2))/(peso1+peso2);
    printf("Media: %.2f",alunos[i].media);
    
    if(alunos[i].media < media_ref){
        printf("\nAluno Reprovado!!\n");
        alunos[i].aprov=0;
    } else {
        printf("\nAluno Aprovado!!\n");
        alunos[i].aprov=1;
    }
}

void alunos_info(tipo_aluno *alunos, int count){

    for (int i=0;i<count;i++){ 
        printf("%d -\t%s: %.2f",alunos[i].num,alunos[i].nome,alunos[i].media);
    }
}
void alunos_aprovados(tipo_aluno *alunos, int qnt_alunos){
    int i;

    for (i=0;i<qnt_alunos;i++){ 
        if(alunos[i].aprov == 1)
            printf("%d -\t%s: %.2f\n",alunos[i].num,alunos[i].nome,alunos[i].media);
    }
}
void alunos_reprovados(tipo_aluno *alunos, int qnt_alunos){
    int i;

    for (i=0;i<qnt_alunos;i++){ 
        if(alunos[i].aprov == 0)
            printf("%d -\t%s: %.2f\n",alunos[i].num,alunos[i].nome,alunos[i].media);
    }
}
void salva_disco(tipo_aluno *alunos, int qnt_alunos){
    int i;
    Arq=fopen("Alunos.txt","wt");

    for(i=0;i<qnt_alunos;i++)
        fprintf(Arq,"%d -\t%s: %.2f\n",alunos[i].num,alunos[i].nome,alunos[i].media); 
}


int main(){
    int menu_opc;
    int *qnt_aluno, count = 0;
    float *media_ref, *peso_p1, *peso_p2;
    tipo_aluno *alunos_ptr;

    qnt_aluno=(int*)malloc(sizeof(int));
    media_ref=(float*)malloc(sizeof(float));
    peso_p1=(float*)malloc(sizeof(float));
    peso_p2=(float*)malloc(sizeof(float));

    printf(">> Gerencia de Turma <<\n");
    while(1){   
        printf("\nMenu:\n1.\tDefinir informacoes da turma\n2.\tInserir aluno e notas\n3.\tExibir alunos e medias\n4.\tExibir alunos aprovados\n5.\tExibir alunos reprovados\n6.\tSalvar dados em Disco\n7.\tSair do programa\n\n");
        printf("Entre com a sua opcao:");
        scanf("%d",&menu_opc);
        
        switch(menu_opc){
            case 1:{
                turma_info(qnt_aluno,media_ref,peso_p1,peso_p2);
                tipo_aluno alunos[*qnt_aluno];
                alunos_ptr = alunos;
                break;
            }
            case 2:{
                inserir_aluno(alunos_ptr, count, *peso_p1, *peso_p2, *media_ref);
                count++;
                break;
            }
            case 3:{
                alunos_info(alunos_ptr,count);
                break;
            }
            case 4:{
                alunos_aprovados(alunos_ptr,*qnt_aluno);
                break;
            }
            case 5:{
                alunos_reprovados(alunos_ptr,*qnt_aluno);
                break;
            }
            case 6:{
                salva_disco(alunos_ptr, *qnt_aluno);
                break;
            }
            case 7:
                return 0;
            
            default:
                printf("Erro! Valor incorreto");
            
        }
    }
}