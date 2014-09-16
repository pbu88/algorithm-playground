#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b){
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

ll divbygcd(ll *a, ll *b){
    ll d = *a > *b? gcd(*a,*b):gcd(*b,*a);
    *a/=d;
    *b/=d;
}

ll combs(int n, int k){
    ll num=1,den=1,tomul,todiv;
    int i;
    if(n/2 < k) k = n-k;
    for(i=k;i;i--){
        tomul = n-i+1;
        todiv = i;
        divbygcd(&tomul,&todiv);
        divbygcd(&tomul, &den);
        divbygcd(&todiv, &tomul);
        num*=tomul;
        den*=todiv;
    }
    return num/den;
}

int main(){
    int n,k;
    ll res;
    while(1){
        scanf("%d %d",&n,&k);
        if(!n && !k) break;
        res = combs(n,k);
        printf("%lld\n",res);
    }
    return 0;
}
