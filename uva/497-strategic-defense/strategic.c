#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int data[MAX_SIZE];
int P[MAX_SIZE];
int M[MAX_SIZE+1];
int S[MAX_SIZE];

char inp[10];

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
    int i=0, r=0, k, n;
    gets(inp);
    n = atoi(inp);
    gets(inp);
    while(n--){
        i=0;
        while(1){
            if(!gets(inp)) break;
            if(!strlen(inp)) break;
            data[i++] = atoi(inp);
        }
        r=solve(i);
        printf("Max hits: %d\n", r);
        k = M[r];
        for(i=r;i>=1;i--){
            S[i-1]=data[k];
            k = P[k];
        }
        for(i=0;i<r;i++) printf("%d\n",S[i]);
        if(n) printf("\n");
    }
    return 0; 
}
