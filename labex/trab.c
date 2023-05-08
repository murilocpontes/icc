#include <stdlib.h>
#include <stdio.h>

int main () {
 char posicoes [3] [3];
 char time = 'x', sflag [4], sj[4],sk[4];
 int flag = 1; 
 int i, j, k;

while (flag) {
    printf("JOGO DA VELHA!!\n(1) Jogar \n (0) Sair \n");
    fflush (stdin);
    fgets(sflag, 2, stdin);
    flag = atoi(sflag);
    if (flag==0)
        break;
    while (1) {
        printf ("Escolha seu simbolo (X ou O):\n");
        fflush(stdin);
        fgets (time, 3, stdin);
        if (time == 'x' || time == 'X') {
            time = 'X';
            break;
        }
        else if (time == 'o' || time == 'O'){
            time = 'O';
            break;
        }
            printf("Erro!! Símbolo incorreto\n");
    }
    for (i=1;i<=10;i++) {
        printf("Rodada %d. Vez de %c",i,time);
        printf("Digite a posição desejada:\n (1,2,3)Linha\n (1,2,3)Coluna\n");
        fflush(stdin);
        fgets(sj,2,stdin);
        fflush(stdin);
        fgets(sk,2,stdin);
        j= atoi(sj);
        k= atoi(sk);
        if (posicoes == 'X' || posicoes == 'O') {
            printf("Erro -> Posicao ja preenchida!\n");
            i--;
            continue;
        }
        if (time == 'X') {
            posicoes [j] [k] = time;
            time = 'O';
        }
        else if (time == 'O') {
            posicoes [j] [k] = time;
            time = 'X';
        }
    }
}
return 0;
}