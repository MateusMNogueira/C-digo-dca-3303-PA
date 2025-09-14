#include <stdio.h>

int main(){
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;
    //item a
    valor = 10;
    p1 = &valor;//Recebe o endereço de valor
    *p1 = 20;//Muda o valor do endereço para 20, que por sua vez eh valor
    printf("Item a: %d\n", valor); //20. Porque o ponteiro p1 aponta para o endereço de valor, e ao alterar o valor apontado por p1, o valor de 'valor' também é alterado.
    //item b
    temp = 26.5;
    p2 = &temp;//Recebe o endereço de  temp
    *p2 = 29.0;//Muda o valor do endereço para 29.0,que por sua vez eh temp
    printf("Item b: %.1f\n", temp); //29.5. Pelo mesmo motivo do item a, o ponteiro p2 aponta para o endereço de temp, e ao alterar o valor apontado por p2, o valor de 'temp' também é alterado.
    //item c
    p3 = &nome[0];//p3 recebe o endereço do primeiro caractere da string "Ponteiros"
    aux = *p3;//aux recebe o valor do endereço apontado por p3, que é 'P'
    printf("Item c: %c\n", aux); // 'P'. Porque p3 aponta para o primeiro caractere da string "Ponteiros", que eh 'P', e esse valor eh atribuído a aux.
    //item d
    p3 = &nome[4];//p3 recebe o endereço do quinto caractere da string "Ponteiros"
    aux = *p3;//aux recebe o valor do endereço apontado por p3, que eh 'e'
    printf("Item d: %c\n", aux); //'e'. Pelo mesmo motivo do item c, p3 aponta para o quinto caractere da string "Ponteiros", que eh 'e', e esse valor eh atribuído a aux.
    //item e
    p3 = nome;//p3 recebe o endereço do primeiro caractere da string "Ponteiros"
    printf("Item e: %c\n", *p3); //'P'. Porque p3 aponta para o primeiro caractere da string "Ponteiros", que eh 'P', e esse valor eh impresso.
    //item f
    p3 = p3 + 4;//p3 avança 4 posições, agora aponta para o quinto caractere da string "Ponteiros"
    printf("Item f: %c\n", *p3); //'e'. Pelo mesmo motivo do item e, p3 agora aponta para o quinto caractere da string "Ponteiros", que eh 'e', e esse valor eh impresso.
    //item g
    p3--;//p3 recua 1 posição, agora aponta para o quarto caractere da string "Ponteiros"
    printf("Item g: %c\n", *p3); //'t'. Pelo mesmo motivo do item e, p3 agora aponta para o quarto caractere da string "Ponteiros", que eh 't', e esse valor eh impresso.
    //item h
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor;//p4 recebe o endereço do primeiro elemento do vetor
    idade = *p4;//idade recebe o valor do endereço apontado por p4, que eh 31
    printf("Item h: %d\n", idade); //31. Porque p4 aponta para o primeiro elemento do vetor, que eh 31, e esse valor eh atribuído a idade.
    //item i
    p5 = p4 + 1;//p5 recebe o endereço do segundo elemento do vetor
    idade = *p5;//idade recebe o valor do endereço apontado por p5, que eh 45
    printf("Item i: %d\n", idade); //45. Pelo mesmo motivo do item h, p5 aponta para o segundo elemento do vetor, que eh 45, e esse valor eh atribuído a idade.
    //item j
    p4 = p5 + 1;//p4 recebe o endereço do terceiro elemento do vetor
    idade = *p4;//idade recebe o valor do endereço apontado por p4, que eh 27
    printf("Item j: %d\n", idade); //27. Pelo mesmo motivo do item h, p4 aponta para o terceiro elemento do vetor, que eh 27, e esse valor eh atribuído a idade.
    //item l
    p4 = p4 - 2;//p4 recua 2 posições, agora aponta para o terceiro elemento do vetor
    idade = *p4;//idade recebe o valor do endereço apontado por p4, que eh 31
    printf("Item l: %d\n", idade); //31. Pelo mesmo motivo do item h, p4 aponta para o primeiro elemento do vetor, que eh 31, e esse valor eh atribuído a idade.
    //item m
    p5 = &vetor[2] - 1;//p5 recebe o endereço do terceiro elemento do vetor e recua 1 posição, agora aponta para o segundo elemento do vetor
    printf("Item m: %d\n", *p5); //45. Porque p5 aponta para o segundo elemento do vetor, que eh 45
    //item n
    p5++;//p5 avança 1 posição, agora aponta para o terceiro elemento do vetor
    printf("Item n: %d\n", *p5); //27. Pelo mesmo motivo do item m, p5 agora aponta para o terceiro elemento do vetor, que eh 27    
    return 0;

}