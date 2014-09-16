#include <stdio.h>

#define CSIZE 5000

typedef long long ll;

int cache[CSIZE] = {0,1};
int mod;

void precomp_fib(){
    int i;
    for(i=2;i<CSIZE;i++){
        cache[i] = (cache[i-1] + cache[i-2])%mod;
    }
}

int fib(int n){
    if(n<CSIZE) return cache[n]%mod;
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
    while(scanf("%d %d",&n, &m) != EOF){
        mod = 1;
        while(m--){
            mod = mod << 1;
        }
        precomp_fib();
        printf("%d\n",fib(n));

    }
    return 0;
}

