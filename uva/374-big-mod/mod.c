#include <stdio.h>

typedef long long int64;

int64 fast_exp(int64 base, int64 exp, int64 mod){
    int64 res = 1;
    while(exp>0){
        if(exp%2==1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res%mod;
}

int main(){
    int64 b,p,m;
    while(scanf("%lld",&b)!=EOF){
        scanf("%lld",&p);
        scanf("%lld",&m);
        scanf("\n");
        printf("%lld\n",fast_exp(b,p,m));
    }
    return 0;
}
