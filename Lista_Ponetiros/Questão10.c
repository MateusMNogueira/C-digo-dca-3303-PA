#include <stdio.h>
int main(){
int vet[] = {4, 9, 13};
int i;
for(i=0;i<3;i++){

    printf("%d ", *(vet+i));
}
return 0;
// Esse código imprime os elementos do vetor usando aritmética de ponteiros.
}


int main(){
int vet[] = {4, 9, 13};
int i;
for(i=0;i<3;i++){
    printf("%X ",vet+i);
}
return 0;
// Esse código imprime os endereços de memória dos elementos do vetor em hexadecimal.
}

