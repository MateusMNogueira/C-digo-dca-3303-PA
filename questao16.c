#include <stdio.h>
void main(){
    float aloha[10]= {1.1,2.2,3.3,4.4};
    float coisas[10][5];
    float *pf;
    float value = 2.2;
    int i = 3;
    aloha[10] ={1.1,2.2,3.3,4.4};
    //A
    //(aloha[2] = value;)
    //printf("%f\n", aloha[2]);
    //O comando é valido, porque está sendo atribuido um valor float a uma posiçao do vetor aloha.
    //B
    //(scanf("%f", &aloha));
    //Comando invaido, pois está tentando atribuir um valor a um vetor.
    //Apesar de não apresentar erro de compilção.
    //C
    //(aloha = "value");
    //Comando inválido, pois está tentando atribuir um valor a um vetor.
   //D 
   //(printf("%f", aloha));
   //Comando invalido %f espera um tipo double mas aloha é um vetor.
   //Item E: 
   //coisas[4][4] = aloha[3];
    //printf("%.1f\n", coisas[4][4]);
    // Comando válido, pois está atribuindo um valor float a uma posiçao da matriz coisas.
   //Item F:
   //coisas[5] = aloha;
   //Comando inválido, pois está tentando atribuir um vetor a uma posiçao da matriz.
    //Item G:
    //pf = value;
    //Comando inválido, pois está tentando atribuir um valor float a um ponteiro.
    //Item H:
    //pf = alhoha;
    //Comando valido, pois está atribuindo o endereço do vetor aloha ao ponteiro pf.
}