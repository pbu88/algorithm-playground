#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100001

int data[MAX_SIZE];
int P[MAX_SIZE];
int M[MAX_SIZE+1];
int S[MAX_SIZE];

/* Longest strictly increasing subsequence in O(nlogn) */
int solve(int length){
    int L, i, lo, hi, mid, newL;
    L=0;
    for(i=0;i<length;i++){
        if(L && data[M[L]] == data[i]) continue;
        lo=1;
        hi=L;
        while(lo<=hi){
            mid=(hi+lo)/2;
            /* if(data[M[mid]] > data[i]) would make it not strictly increasing */
            if(data[M[mid]] >= data[i])
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
    /* usage example: 
     * input file can be:
       10
       1 2 3 4 5 6 7 8 9 10
       10
       1 1 1 1 1 1 1 1 1 1
       10
       5 19 5 81 50 28 29 1 83 23

     * and the output will be the length and the indexes:
       
       10
       0 1 2 3 4 5 6 7 8 9
       1
       7
       5
       0 1 5 6 8

     * compared to the O(n^2) version this algortihm literally flies :)
    */

    int i=0, r=0, k;
    int n;
    while(1){
        if(scanf("%d", &n) == EOF) break;
        memset(P, 0, sizeof(P));
        memset(M, 0, sizeof(M));
        memset(S, 0, sizeof(S));
        for(int i=0;i<n;i++){
            scanf("%d", &data[i]);
        }
        r=solve(n);
        printf("%d\n", r);
        k = M[r];
        for(i=r;i>=1;i--){
            S[i-1]=k;
            k = P[k];
        }
        for(i=0;i<r;i++){
            printf("%d",S[i]);
            if(i==(r-1)) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
