#include <stdio.h>

int train[50];

int bubble_sort(int l){
    int i,j,res=0;
    for(i=0;i<l;i++){
        for(j=l-1;j>i;j--){
            if(train[j] < train[j-1]){
                train[j] ^= train[j-1];
                train[j-1] ^= train[j];
                train[j] ^= train[j-1];
                res++;
            }
        }
    }
    return res;
}

int main(){
    int t,n,i,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d", &train[i]);
        }
        r = bubble_sort(n);
        printf("Optimal train swapping takes %d swaps.\n",r);
        
    }
}
