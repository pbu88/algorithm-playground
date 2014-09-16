#include <stdio.h>

#define CSIZE 10000

typedef long long ll;

int cache[20][CSIZE];

int mod;
int cache_i;

void precomp_fib(){
    int i,j;
    mod = 1;
    for(j=0;j<20;j++){
        mod = 1 << j;
        cache[j][0] = 0;
        cache[j][1] = 1;
        for(i=2;i<CSIZE;i++){
            cache[j][i] = (cache[j][i-1] + cache[j][i-2])%mod;
        }
    }
}

int fib(int n){
    if(n<CSIZE) return cache[cache_i][n]%mod;
    if(n%2==0){
        ll fn1 = fib(n/2-1);
        ll fn  = fib(n/2);
        return ( ((((2*fn1)%mod) + fn )%mod) *(fn%mod ))%mod;
    }
    else{
        ll fn1 = fib(n/2);
        ll fn = fib(n/2+1);
        return ((fn1%mod)*(fn1%mod) + (fn%mod)*(fn%mod))%mod;
    }

}

int main(){
    int n,m;
    precomp_fib();
    while(scanf("%d %d",&n, &m) != EOF){
        cache_i = m;
        mod = 1 << m;
        printf("%d\n",fib(n));

    }
    return 0;
}

