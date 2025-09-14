int main(){
    //tipo x[4];
    // x[0] no endereço 4092
    //char c;// 1 byte
    //int i;// 2 bytes
    //float f;// 4 bytes
    //double d;// 8 bytes
    /*valores de x+1,x+2,x+3. Se x for declarado como cada tipo.
    Para char:
    x+1 = 4093;
    x+2 = 4094;
    x+3 = 4095;
    Para int:
    x+1 = 4094;
    x+2 = 4096;
    x+3 = 4098;
    Para float:
    x+1 = 4096;
    x+2 = 4100;
    x+3 = 4104;
    Para double:
    x+1 = 4100;
    x+2 = 4108;
    x+3 = 4116;
    Valores teóricos, podem variar conforme o compilador e arquitetura do sistema.
    */
   //Teste prático:
    char x_char[4] = {'a','b','c','d'};//declarando e inicializando do tipo char
    int x_int[4] = {1,2,3,4};//declarando e inicializando do tipo int
    float x_float[4] = {1.1,2.2,3.3,4.4};//declarando e inicializando do tipo float
    double x_double[4] = {1.11,2.22,3.33,4.44};//declarando e inicializando do tipo double
    printf("char:\n");
    for(int i=0;i<4;i++){
        printf("Endereco de x_char[%d]: %p\n",i,(void*)&x_char[i]);
    }
    //Endereco de x_char[0]: 000000C9615FFC1C
    //Endereco de x_char[1]: 000000C9615FFC1D
    //Endereco de x_char[2]: 000000C9615FFC1E
    //Endereco de x_char[3]: 000000C9615FFC1F
    printf("\nint:\n");
    for(int i=0;i<4;i++){
        printf("Endereco de x_int[%d]: %p\n",i,(void*)&x_int[i]);
    }
    //Endereco de x_int[0]: 000000C9615FFC00
    //Endereco de x_int[1]: 000000C9615FFC04
    //Endereco de x_int[2]: 000000C9615FFC08
    //Endereco de x_int[3]: 000000C9615FFC0C
    printf("\nfloat:\n");
    for(int i=0;i<4;i++){
        printf("Endereco de x_float[%d]: %p\n",i,(void*)&x_float[i]);
    }
    //Endereco de x_float[0]: 000000C9615FFBF0
    //Endereco de x_float[1]: 000000C9615FFBF4
    //Endereco de x_float[2]: 000000C9615FFBF8
    //Endereco de x_float[3]: 000000C9615FFBFC
    printf("\ndouble:\n");
    for(int i=0;i<4;i++){
        printf("Endereco de x_double[%d]: %p\n",i,(void*)&x_double[i]);
    }
    //Endereco de x_double[0]: 000000C9615FFBE0
    //Endereco de x_double[1]: 000000C9615FFBE8
    //Endereco de x_double[2]: 000000C9615FFBF0
    //Endereco de x_double[3]: 000000C9615FFBF8

    return 0;
}