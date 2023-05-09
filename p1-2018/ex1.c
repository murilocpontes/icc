#include <stdlib.h>
#include <stdio.h>

#define MAXDIGITS 8

int main () {
    char inicio [MAXDIGITS];
    char fim [MAXDIGITS];
    int i,j;
    int restart, flag = 1, hortomin;
    int horai, horaf, mini, minf, diffmin, diffhora;
    char shorai[4], shoraf[4], smini[4], sminf[4];

    while (flag) { //pensar em uma flag
        printf ("Insira o horario de inicio do jogo:(hh:mm)\n");
        fflush(stdin);
        fgets(inicio, 7, stdin);
        printf ("Insira o horario de fim do jogo:(hh:mm)\n");
        fflush(stdin);
        fgets (fim, 7, stdin);
        restart = 0;
        hortomin = 0;
        j = 0;

        for (i=0;i<5;i++) {
            if (isdigit(inicio[i]) == 0) { 
                //validação inicio
                if (inicio[i] == ':' && i == 2) {
                    hortomin=1;
                    continue;
                }
                else {
                    printf ("Erro: Hora invalida!\n");
                    restart = 1;
                    break;
                }
            }//dividindo h e min em strings diferentes
            else if(hortomin == 0) {
                shorai[i]=inicio[i];
            }
            else 
                smini[j] =inicio[i];

        if (isdigit(fim[i]) == 0) { 
            //validação fim
                if (fim[i] == ':' && i == 2) {
                    continue;
                }
                else {
                    printf ("Erro: Hora invalida!\n");
                    restart = 1;
                    break;
                }
            } //dividindo h e min em strings diferentes
            else if(hortomin == 0) {
                shoraf[i]=fim[i];
            }
            else {
                sminf[j] =fim[i];
                j++;
            }
        }

        if (restart == 1)
            continue;
        horai = atoi(shorai);
        mini = atoi (smini);
        horaf = atoi(shoraf);
        minf = atoi (sminf);

        if(horai >24 || horaf >24 || mini >60 || minf >60) {
            printf("Erro. Hora incorreta!\n");
            continue;
        }
        diffhora = horaf - horai;
        diffmin = minf - mini;
        if (diffhora<0) {
            diffhora = 24 + diffhora; 
        }
        if (diffmin<0) {
            diffhora--;
            diffmin = 60 + diffmin;
        }
        printf("O jogo durou: %d:%d\n",diffhora, diffmin);
        flag = 0;
    }
return 0;    
}
