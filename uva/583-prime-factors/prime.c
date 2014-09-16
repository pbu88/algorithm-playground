#include <stdio.h>
#include <string.h>

#define SSIZE 50000

char sieve[SSIZE];
int primes[SSIZE];
int pi = 0;
int sol[40];

void compute_sieve(){
    int i,j;
    for(i=2;i<SSIZE;i++){
        if(sieve[i]) continue; 
        primes[pi++] = i;
        for(j=i+i;j<SSIZE;j+=i){
            sieve[j] = 1;
        }
    }
}

int main(){
    int sol[40];
    int soli;
    int n,copyn,i;
    compute_sieve();
    while(1){
        scanf("%d",&n);
        if(!n) break;
        memset(sol,0,sizeof(int)*40);
        soli = 0;
        i = 0;
        copyn = n > 0 ? n : -n;
        if(n<0){
            sol[soli++] = -1;
        }
        while(copyn>1){
            if(copyn%primes[i]==0){
                copyn/=primes[i];
                sol[soli++] = primes[i];
            }
            else{
                i++;
                if(i==pi) break;
            }
        }
        if(copyn != 1) sol[soli++] = copyn;
        printf("%d = %d",n, sol[0]);
        for(i=1;i<soli;i++){
            printf(" x %d",sol[i]);
        }
        printf("\n");
    }
    return 0;
}
