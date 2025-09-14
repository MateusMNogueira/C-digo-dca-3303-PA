int qc_float(const void *a, const void *b){//funcao de comparacao para float
    float fa = *(const float*) a; //convertendo ponteiros para float
    float fb = *(const float*) b; //convertendo ponteiros para float
    if (fa < fb) return -1;//se a < b. a vem antes de b
    if (fa > fb) return 1;//se a > b. b vem antes de a
    return 0;
}
int main(){
    int n;
    scanf("%d", &n);
    float *v = malloc(n * sizeof(float));//alocando vetor dinamicamente
    for(int i = 0; i < n; i++){
        scanf("%f", &v[i]);
    }//lendo os valores
    qsort(v, n, sizeof(float), qc_float);//ordenando o vetor 
    for(int i = 0; i < n; i++){
        printf("%.2f ", v[i]);
    }//imprimindo os valores ordenados com 2 casas decimais
    free(v);//liberando a memoria alocada
    return 0;
    
}