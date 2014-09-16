#include <stdio.h>

int buff[1001];

int bubble_sort(int l){
    int i,j,res=0;
    for(i=0;i<l;i++){
        for(j=l-1;j>i;j--){
            if(buff[j] < buff[j-1]){
                buff[j] ^= buff[j-1];
                buff[j-1] ^= buff[j];
                buff[j] ^= buff[j-1];
                res++;
            }
        }
    }
    return res;
}

int main(){
    int n,i,r;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d", &buff[i]);
        }
        r = bubble_sort(n);
        printf("Minimum exchange operations : %d\n",r);
        
    }
    return 0;
}
