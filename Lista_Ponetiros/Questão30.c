#include <stdio.h>
#include <stdlib.h>
//Para alocar matriz tridimensional
int ***alocaMatirz(int colunas, int linhas, int profundidade){
    int ***matriz;//declarando a matriz tridimensional
    int i, j;//variaveis de controle
    matriz = (int ***)malloc(profundidade * sizeof(int **));//alocando a primeira dimensao
    matriz[0] = (int **)malloc(profundidade * linhas * sizeof(int *));//alocando a segunda dimensao
    matriz[0][0] = (int *)malloc(profundidade * linhas * colunas * sizeof(int));//alocando a terceira dimensao
    //lacos para completar a alocacao da segunda para a terceira dimensao
    for(i=0;i<linhas;i++){
        matriz[i] = matriz[0]+i*profundidade;
        for(j=0;j<profundidade;j++){
            matriz[i][j] = matriz[0][0]+(i*profundidade+j)*colunas;
        }
    }
    return matriz;//retornando a matriz
}
//Para liberar a matriz tridimensional
void liberaMatriz(int ***matriz,int colunas, int linhas){
    free(matriz[0][0]);//liberando a terceira dimensao
    free(matriz[0]);//liberando a segunda dimensao
    free(matriz);//liberando a primeira dimensao
}
//Imprimindo um plano da matriz tridimensional
void imprimePlano(int ***matriz, int colunas, int linhas, int profundidade, int plano){
    printf("Plano %d:\n", plano);
    for(int i=0;i<colunas;i++){
        for(int j=0;j<linhas;j++){
            printf("%d ", matriz[i][j][plano]);
        }
        printf("\n");
    }
}
//Para modificar o estado de um dos elementos da matriz tridimensional
void modificaElemento(int ***matriz, int i, int j, int k, int valor){
    matriz[i][j][k] = valor;
}
//Funcao principal
int main(){
    int linhas,colunas,profundidade,plano;
    int imodificar, jmodificar, kmodificar, valormodificar;
    printf("Digite o numero de colunas, linhas e profundidade da matriz: ");
    scanf("%d %d %d", &colunas, &linhas, &profundidade);
    int ***matriz = alocaMatirz(colunas, linhas, profundidade);//alocando a matriz
    //Preenchendo a matriz com valores iniciais aleatorios
    for(int i=0;i<colunas;i++){
        for(int j=0;j<linhas;j++){
            for(int k=0;k<profundidade;k++){
                matriz[i][j][k] = rand() % 2; // Valores aleatórios entre 0 e 1
            }
        }
    }
    printf("Digite o plano que deseja imprimir: ");
    scanf("%d", &plano);
    imprimePlano(matriz, colunas, linhas, profundidade, plano);//imprimindo o plano desejado
    //Modificando um elemento da matriz
    printf("Digite o valor de i: ");
    scanf("%d", &imodificar);
    printf("Digite o valor de j: ");
    scanf("%d", &jmodificar);
    printf("Digite o valor de k: ");
    scanf("%d", &kmodificar);
    printf("Digite o novo valor: ");
    scanf("%d", &valormodificar);
    modificaElemento(matriz, imodificar, jmodificar, kmodificar, valormodificar);//modificando o elemento
    //Imprimindo o plano novamente para ver a modificacao
    imprimePlano(matriz, colunas, linhas, profundidade, plano);
    //Liberando a matriz
    liberaMatriz(matriz, colunas, linhas);
    return 0;
}
/*Precisa liberar 3 vezes pois foi usado malloc 3 vezes
Para não dar memory leak
*/

