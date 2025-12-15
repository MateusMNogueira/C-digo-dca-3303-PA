#include <stdio.h>
#include <stdlib.h>
int main(){
    int a, b;
    int x, y, z;
    scanf("%d %d", &a, &b);//10 1
    x = a; y = b; z = a + b;
    while (a) {
        x = x | b;
        y = y ^ a;
        z = z & (a+b);
        a = a >> 1;
        b = b << 1;
}
printf ("%d %d %d\n", x, y, z);//15 13 0
//passo a passo 
/*a = a >> 1; Operacao de deslocamento de bits para direita
b = b << 1; Operacao de deslocamento de bits para esquerda
Para a = 10 e b = 1
x = 10 | 1 = 11 (bit a bit)
y = 1 ^ 10 = 11
z = 11 & (10+1=11) = 11(comparacao bit a bit)
a = 10 >> 1 = 5
b = 1 << 1 = 2
Para a = 5 e b = 2
x = 11 | 2 = 11
y = 11 ^ 5 = 14
z = 11 & 7 = 3
a = 5 >> 1 = 2
b = 2 << 1 = 4
Para a = 2 e b = 4
x = 11 | 4 = 15
y = 14 ^ 2 = 12
z = 3 & 6 = 2
a = 2 >> 1 = 1
b = 4 << 1 = 8
Para a = 1 e b = 8
x = 15 | 8 = 15
y = 12 ^ 1 = 13
z = 2 & 9 = 0
a = 1 >> 1 = 0
b = 8 << 1 = 16
*/
return 0;
}
