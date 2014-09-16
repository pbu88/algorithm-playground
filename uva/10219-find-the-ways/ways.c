#include <stdio.h>
#include <math.h>

typedef long long ll;

int main(){
    int i;
    ll n,k;
    double res;
    while(scanf("%lld %lld",&n,&k)!=EOF){
        res = 0;
        if(k>n/2) k = n-k;
        for(i=1;i<=k;i++)
            res += log10(n-i+1) - log10(i);
        res = floor(res) + 1;
        printf("%0.lf\n",res);

    }
    return 0;
}
