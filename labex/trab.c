#include <stdlib.h>
#include <stdio.h>

int conditiontest(char posicoes[3][3], int j, int k){
    if(posicoes[j][0] == posicoes[j][1] && posicoes[j][0] == posicoes [j][2])
        return 1;
        
    if(posicoes[0][k] == posicoes[1][k] && posicoes[0][k] == posicoes [2][k])
        return 1;
    
    if(j!=1 && k!=1 && k!=j)//fowardslash
        if(posicoes[0][2] == posicoes[1][1] && posicoes[0][2] == posicoes [2][0])
        return 1;
            
    if(j!=1 && k!=1 && k==j)//backslash
        if(posicoes[0][0] == posicoes[1][1] && posicoes[0][0] == posicoes [2][2])
            return 1;
        
        if(j==1 && k==1){  //ambas diagonais
            if(posicoes[0][2] == posicoes[1][1] && posicoes[0][2] == posicoes [2][0]){
                return 1;
            }
            if(posicoes[0][0] == posicoes[1][1] && posicoes[0][0] == posicoes [2][2]){
                return 1;
            }
        }
}

void tabuleiro(char posicoes[3][3]){
    int i, j;
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(posicoes [i][j] == 'e'){
                if(j==0 || j==1) 
                    printf("   │");   
                else
                    printf("   \n");
            }
            else{
                if(j==0 || j==1) 
                    printf(" %c │", posicoes[i][j]);   
                else
                    printf(" %c \n", posicoes[i][j]);
            }
        }
        if (i<2)
            printf("───┼───┼───\n");
    }
    printf("\n");
}

int main(){
    char posicoes[3][3];
    char simb, sgameon[3], sj[3],sk[3];
    int gameon = 1, vitoria = 0;
    int i, j, k;
    int escolha_j, escolha_k;

    while (gameon){
        printf("JOGO DA VELHA!!\n(1) Jogar \n(0) Sair \n");
        fflush(stdin);
        fgets(sgameon, 3, stdin);
        gameon = atoi(sgameon);
        system("clear");

        if (gameon==0)
            break;
        
        while (1){
            printf ("Escolha seu simbolo (X ou O):\n");
            fflush(stdin);
            simb = getchar();
            getchar(); // pegar o \n (fflush n ta legal)
            if(simb == 'x' || simb == 'X'){
                simb = 'X';
                system("clear");
                break;
            }
            else if(simb == 'o' || simb == 'O'){
                simb = 'O';
                system("clear");
                break;
            }
                printf("Erro -> Símbolo incorreto\n");
        }

        for(i=0;i<3;i++){
            for (j=0;j<3;j++){
                posicoes[i][j] = 'e';
            }
        }

        for(i=1;i<10;i++){
            printf("Rodada %d. Vez de %c.\n",i,simb);
            printf("Digite a posição desejada:\n (1,2,3)Linha\n");
            fgets(sj,3,stdin);

            printf("(1,2,3)Coluna\n");
            fgets(sk,3,stdin);

            j = atoi(sj) - 1;
            k = atoi(sk) - 1;

            if(j>3 || k>3 || j<0 || k<0) {
                printf("Erro -> Numero invalido!\n");
                i--;
                continue;
            }

            if(posicoes[j][k] == 'X' || posicoes[j][k] == 'O'){
                printf("Erro -> Posicao ja preenchida!\n");
                i--;
                continue;
            }
            else {
                posicoes[j][k] = simb;
                system("clear");
                tabuleiro(posicoes);

                //antes da quinta jogada, n tem como ganhar
                if(i < 5) {
                    if(simb == 'X')
                        simb = 'O';
                    else
                        simb = 'X';
                    continue;
                }

                vitoria = conditiontest(posicoes, j, k);
                if(vitoria == 1)
                    break;

                //troca de time no fim do turno
                if(simb == 'X')
                    simb = 'O';
                else
                    simb = 'X';
            }
        }
            if(vitoria == 1)
                printf("\nO JOGADOR %c VENCEU!\n\n", simb);
            else
                printf("DEU VELHA!\n");
        
    }
return 0;
}