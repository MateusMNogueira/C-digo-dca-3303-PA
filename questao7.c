int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco\n");
    for(i=0;i<4;i++){
        printf("i = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]);
        printf(" *(f + %d) = %.1f",i, *(f+i));
        printf(" &vet[%d] = %X",i, &vet[i]);
        printf(" (f + %d) = %X",i, f+i);
        printf("\n");
    }
    // os endereços aumentam de 4 em 4 bytes.
    //i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = 8AFFF960 (f + 0) = 8AFFF960
    //i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = 8AFFF964 (f + 1) = 8AFFF964
    //i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = 8AFFF968 (f + 2) = 8AFFF968
    //i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = 8AFFF96C (f + 3) = 8AFFF96C
    
    return 0;
}