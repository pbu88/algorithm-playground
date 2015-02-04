#include <stdio.h>
#include <math.h>

#define PHI 1.618
#define MOD 1000000007
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
    int t,n,m,sum,sum2,res;
    precomp_fib();
    /*scanf("%d",&t);
    sum = fib(t);
    printf("%d\n",sum);*/
    int i;
    scanf("%d",&t);
    while(t--){
        sum = 0;
        scanf("%d %d",&n,&m);
        sum = fib(n+1)-1;
        sum2 = fib(m+2)-1;
        if(sum2<sum) sum2+=MOD;
        printf("%d\n",(sum2-sum)%MOD);
    }
    return 0;
}
