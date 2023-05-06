#include <stdlib.h>
#include <stdio.h>

int main () {
 int posicoes [3] [3];
 char time = 'x', sflag [3];
 int flag = 1; 

while (flag) {
    printf("JOGO DA VELHA!!\n(1) Jogar \n (0) Sair \n");
    fflush (stdin);
    fgets(sflag, 2, stdin);
    flag = atoi(sflag);
    
}
return 0;
}