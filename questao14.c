#include <stdio.h>
int f(int a,int *pb,int **ppc){
    int b,c;
    **ppc+=1;
    c=**ppc;
    *pb+=2;
    b = *pb;
    a+=3;
    return a+b+c; 
}
void main(){
    int c,*b,**a;
    c = 5;
    b = &c;
    a = &b;
    printf("%d\n", f(c, b, a));
    getchar();
    return 0;
}
/*Na função main, a variável c é inicializada com o valor 5. O ponteiro b aponta para c, e o ponteiro de ponteiro a aponta para b.
Quando a função f é chamada, os seguintes passos ocorrem:
1. **ppc é incrementado em 1, então c passa de 5 para 6.
2. c é atribuído a variável local c dentro da função f, então c agora é 6.
3. *pb é incrementado em 2, então c passa de 6 para 8.
4. b é atribuído a variável local b dentro da função f, então b agora é 8.
5. a é incrementado em 3, então a passa de 5 para 8.(o valor a independe do valor alterado das operações passadas)
6. Finalmente, a função retorna a soma de a, b e c, que é 8 + 8 + 6 = 22.
*/