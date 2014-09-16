#include <stdio.h>
#include <math.h>

int max,divs;

int divisors(int n){
    int i=2,res=2,step=1;
    int sqrt_n = (int)sqrt((double)n);
    if(n%2!=0){
        step=2;
        i = 3;
    }
    for(;i<=sqrt_n;i+=step){
        if(n%i==0) res+=2;
    }
    if(sqrt_n*sqrt_n == n) res--;
    return res;
}

void div_range(int u, int l){
    max = divs = 0;
    for(;u<=l;u++){
        int aux = divisors(u);
        if(aux > divs){
            max = u;
            divs = aux;
        }
    }
}

int main(){
    int u,l,n;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&u,&l);
        div_range(u,l);
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",
                u,l,max,divs);
    }
    
    return 0;
}
