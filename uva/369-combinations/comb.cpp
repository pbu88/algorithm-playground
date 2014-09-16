#include <stdio.h>

int gcd(int a, int b){
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

int divbygcd(int& a, int& b){
    int d = a > b? gcd(a,b):gcd(b,a);
    a/=d;
    b/=d;
}

int combs(int n, int k){
    int num=1,den=1,tomul,todiv,i;
    if(n/2 < k) k = n-k;
    for(i=k;i;i--){
        tomul = n-i+1;
        todiv = i;
        divbygcd(tomul,todiv);
        divbygcd(tomul, den);
        divbygcd(todiv, tomul);
        num*=tomul;
        den*=todiv;
    }
    return num/den;
}

int main(){
    int n,k,res;
    while(1){
        scanf("%d %d",&n,&k);
        if(!n && !k) break;
        res = combs(n,k);
        printf("%d things taken %d at a time is %d exactly.\n",
                n,
                k,
                res);
    }
    return 0;
}
