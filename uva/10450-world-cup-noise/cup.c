#include <stdio.h>

#define CSIZE 50

typedef long long ll;

ll cache[CSIZE] = {0,1};

void precomp_fib(){
    int i;
    for(i=2;i<CSIZE;i++){
        cache[i] = (cache[i-1] + cache[i-2]);
    }
}

ll fib(int n){
    if(n==2) return 0;
    if(n<CSIZE) return cache[n];
    if(n%2==0){
        ll fn1 = fib(n/2-1);
        ll fn  = fib(n/2);
        return ( ((((2*fn1)) + fn )) *(fn ));
    }
    else{
        ll fn1 = fib(n/2);
        ll fn = fib(n/2+1);
        return ((fn1)*(fn1) + (fn)*(fn));
    }

}

int main(){
    int n,t,i=1;
    precomp_fib();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Scenario #%d:\n%lld\n\n",i++,fib(n+2));
    }
    return 0;
}

