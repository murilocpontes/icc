#include <stdio.h>
#include <stdlib.h>
int main()
{
  float salario, reaj;
  float ts, bonus;
  float salfin;
  printf("Digite o seu salario:\n");
  scanf("%f",&salario);
  printf("Ha quantos anos voce eh funcionario da empresa?\n");
  scanf("%f",&ts);
 if (salario <= 500.00){
   reaj= (float) (salario*1.25);
   printf("Seu salario foi reajustado para: %.2f\n",reaj);
 }
 else if(salario>500 && salario<=1000) {
    reaj= (float) (salario*1.20);
    printf("Seu salario foi reajustado para: %.2f\n",reaj);
 }
 else if (salario>1000 && salario<=1500) {
    reaj= (float) (salario*1.15);
    printf("Seu salario foi reajustado para:%.2f\n",reaj);
 }
 else if (salario>1500 && salario<=2000) {
    reaj = (float) (salario*1.10);
    printf("Seu salario foi reajustado para: %.2f\n",reaj);
 }
 else {
    reaj = salario;
    printf("Voce nao recebera reajuste\n");
 }
 if (ts==0) {
    bonus=0;
    printf("Voce nao recebe bonus por tempo de servico\n");
 }
 else if (ts >=1 && ts<=3) {
    bonus= 100;
    printf("Voce recebera um bonus de %.2f\n",bonus);
 }
 else if (ts>= 4 && ts<= 6) {
    bonus=200;
    printf("Voce recebera um bonus de %.2f\n",bonus);
 }
 else if (ts >=7 && ts <=10){
    bonus= 300;
    printf("Voce recebera um bonus de %.2f\n",bonus);
 }
 else {
    bonus= 500;
    printf("Voce recebera um bonus de %.2f\n",bonus);
 }
 salfin= reaj + bonus;
 if (salfin == salario)
    printf("Seu salario permaneceu o msm\n");
 else
    printf("Seu salario agora eh: %.2f\n",salfin);
 return 0;
}