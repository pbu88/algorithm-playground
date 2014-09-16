#include <stdio.h>
#define MAX_SIZE 100000

int data[MAX_SIZE];
int P[MAX_SIZE];
int M[MAX_SIZE+1];
int S[MAX_SIZE];

int solve(int length){
    int L, i, lo, hi, mid, newL;
    L=0;
    for(i=0;i<length;i++){
        if(L && data[M[L]] == data[i]) continue;
        lo=1;
        hi=L;
        while(lo<=hi){
            mid=(hi+lo)/2;
            if(data[M[mid]] > data[i])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        newL = lo;
        P[i] = M[newL-1];
        if(newL > L){
            L = newL;
            M[newL]=i;
        }
        else if(data[M[newL]] > data[i]){
            M[newL] = i;
        }
    }
    return L;
}

int main(){
    int tmp, i=0, r=0, k;
    while(scanf("%d", &tmp)!=EOF){
        data[i++] = tmp;                
    }
    r=solve(i);
    printf("%d\n-\n", r);
    k = M[r];
    for(i=r;i>=1;i--){
        S[i-1]=data[k];
        k = P[k];
    }
    for(i=0;i<r;i++) printf("%d\n",S[i]);
    return 0; 
}
