#include <stdio.h>
#define BUFFSIZE 100000

int buffer[BUFFSIZE];
int M[BUFFSIZE+1];

int solve(int length){
    int i, L, hi, lo, mid;
    L = 0;
    for(i=0; i<length; i++){
        lo = 1;
        hi = L;
        while(lo<=hi){
            mid = (hi+lo)/2;
            if(buffer[M[mid]] > buffer[i])
                lo = mid+1;
            else
                hi = mid-1;
        }
        int newL = lo;
        if(newL > L){
            L=newL;
            M[L]=i;
        }
        else if(buffer[M[newL]] < buffer[i]){
            M[newL]=i;
        }
    }
    return L;
}

int main(){
    int i=0, tmp=0, r, tests=1;
    while(1){
        scanf("%d",&tmp);
        if(tmp == -1){
            break;
        }
        if(tests!=1) printf("\n");
        i = 0;
        buffer[i++] = tmp;
        while(1){
            scanf("%d",&tmp);
            if(tmp == -1){
                r = solve(i);
                break;
            }
            buffer[i++] = tmp;
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n", tests++, r);
    }
    return 0;
}
