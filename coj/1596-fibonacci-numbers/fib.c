#include <stdio.h>

#define MOD 1000000000
#define CSIZE 2000000

typedef long long ll;

int cache[CSIZE] = {0,1};

void precomp_fib(){
    int i;
    for(i=2;i<CSIZE;i++){
        cache[i] = (cache[i-1] + cache[i-2])%MOD;
    }
}

int fib(int n){
    if(n<CSIZE) return cache[n];
    if(n%2==0){
        ll fn1 = fib(n/2-1);
        ll fn  = fib(n/2);
        return ( ((((2*fn1)%MOD) + fn )%MOD) *(fn%MOD ))%MOD;
    }
    else{
        ll fn1 = fib(n/2);
        ll fn = fib(n/2+1);
        return ((fn1%MOD)*(fn1%MOD) + (fn%MOD)*(fn%MOD))%MOD;
    }

}

int main(){
    int t,n;
    precomp_fib();
    int i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%09d\n",fib(n));
    }
    return 0;
}