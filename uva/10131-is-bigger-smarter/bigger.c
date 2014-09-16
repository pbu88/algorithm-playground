#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1001

typedef struct elephant{
    int id;
    int w;
    int s;
} elephant;

elephant inp[MAX_SIZE];
int P[MAX_SIZE];
int M[MAX_SIZE+1];
int seq[MAX_SIZE];

int compar(const void* a, const void* b){
    elephant* elephant_a = (elephant*)a;
    elephant* elephant_b = (elephant*)b;
    return elephant_a->w - elephant_b->w;
}

int lis(int length){
    int L,newL,lo,hi,mid,i;
    L=0;
    for(i=0;i<length;i++){
        lo=1;
        hi=L;
        while(lo<=hi){
            mid=(lo+hi)/2;
            if(inp[M[mid]].s > inp[i].s)
                lo=mid+1;
            else
                hi=mid-1;
        }
        newL=lo;
        P[i]=M[newL-1];
        if(inp[i].w <= inp[P[i]].w) continue;
        if(newL>L){
            L=newL;
            M[newL]=i;
        }
        else if(inp[M[newL]].s < inp[i].s){
            M[newL]=i;
        }
    }
    return L;
}

int main(){
    int w, s, n=0, i, r;
    while(scanf("%d %d",&w, &s)!=EOF){
        inp[n].id = n+1;
        inp[n].w = w;
        inp[n].s = s;
        n++;
    }
    qsort(inp, n, sizeof(elephant), &compar);
    r=lis(n);
    printf("%d\n", r);
    n=r;
    i=M[r];
    while(r){
        seq[r-1] = inp[i].id;
        i=P[i];
        r--;
    }
    for(i=0;i<n;i++){
        printf("%d\n",seq[i]);
    }


}
