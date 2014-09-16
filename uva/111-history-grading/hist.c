#include <stdio.h>
int original[20];
int resp[20];
int rank[20];

int M[21];

int solve(int n){
    int i,j;
    int L = 0;
    int lo, mid, hi;
    for(i=0;i<n;i++){
        lo = 1;
        hi = L;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(rank[resp[M[mid]]] < rank[resp[i]])
                lo=mid+1;
            else
                hi=mid-1;
        }
        int newL = lo;
        if(newL > L){
            M[newL] = i;
            L = newL;
        }
        else if(rank[resp[M[newL]]] > rank[resp[i]]){
            M[newL] = i;
        }
    }
    return L;
}

int main(){
    int n,i,res,tmp;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &original[i]);
        rank[i] = original[i]-1;
    }
    while(scanf("%d", &tmp) != EOF){
        resp[tmp-1] = 0;
        for(i=1;i<n;i++){
            scanf("%d", &tmp);
            resp[tmp-1] = i;
        }
        res = solve(n);
        printf("%d\n", res);
    }
    return 0;
}
