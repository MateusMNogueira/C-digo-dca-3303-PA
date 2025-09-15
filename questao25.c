// descobrir qual esta ocorrendo um vazamento de memoria
//(A)
void f( ){
void *s;
s = malloc(50);
free(s);
}//esta tudo certo
//(B)
int f( ){
float *a;
return 0;
}//esta tudo certo
//(C)
int f(char *data){
void *s;
s = malloc(50);
int size = strlen(data);
if (size > 50)
return(-1);
free(s);
return 0;
}//tem vazamento de memoria pois se o size for maior que 50 o free nao sera executado
//(D)
int *f(int n){
int *num = malloc(sizeof(int)*n);
return num;
}
int main(void){
int *num;
num = f(10);
free(num);
return 0;
}//esta tudo certo
//(E)
void f(int n){
char *m = malloc(10);
char *n = malloc(10);
free(m);
m = n;
free(m);
free(n);
}//esta errado pois tem um double free mas nao tem vazamento de memoria