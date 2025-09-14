
int ordenação(float *v, int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(v[j]<v[min]){
                min=j;
            }
        }
        if(min!=i){
        float aux=v[i];
        v[i]=v[min];
        v[min]=aux;
    }
    }
    return v;
}
    int main(){
        int n;
        scanf("%d",&n);
        float *v=(float*)malloc(n*sizeof(float));
        for(int i=0;i<n;i++){
            scanf("%f",&v[i]);
        }
        ordenação(v,n);
        for(int i=0;i<n;i++){
            printf("%.2f ",v[i]);
        }
        free(v);
        return 0;
    }