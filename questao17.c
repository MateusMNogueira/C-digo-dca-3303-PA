#include <stdio.h>
#include <stdlib.h>//Biblioteca para usar malloc e free
/*Memory leak eh quando uma memória alocada deixa de ser referenciada e nao eh liberada*/
//Exemplo de memory leak
/*int main(){
    int *p = (int *) malloc(10*sizeof(int));
    if(p == NULL){
    printf("Erro de alocacao\n");
    return 1;
    }
    for(int i = 0; i < 10; i++){
        p[i] = i;
        printf("%d ", p[i]);
    }


    return 0;
}*/
//Corrigindo o memory leak
int main(){
    int *p = (int *) malloc(10*sizeof(int));
    if(p == NULL){
        printf("Erro de alocacao\n");
        return 1;
    }
    for(int i = 0; i < 10; i++){
        p[i] = i;
        printf("%d ", p[i]);
    }
    
    free(p);
    return 0;
}