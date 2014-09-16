
#include <stdio.h>
#include <string.h>

#define PREC 5002

char op1[PREC];
char op2[PREC];
char res[PREC];

char fibo_cache[PREC][PREC] = {"0","1"};
int fibo_cache_count = 1;

set_op1(int n){
    if(n==0){
        memcpy(op1,"0",2);
    }
    int i = 0;
    while(n){
        op1[i++] = n%10+'0';
        n/=10;
    }
    op1[i] = 0;
}

void rev(char v[]){
    int l = strlen(v);
    int i;
    char cc;
    for(i=0;i<l-1-i;i++){
        cc = v[i];
        v[i] = v[l-1-i];
        v[l-1-i] = cc;
    }
}

void add(){
    memset(res,0,PREC);
    int rem = 0;
    int i, l1 = strlen(op1), l2 = strlen(op2);
    int l = l1 > l2 ? l1 : l2;

    for(i=0;i<l;i++){
        if(i >= l1) op1[i] = '0';
        if(i >= l2) op2[i] = '0';
        int aux = (op1[i] - '0') + (op2[i] - '0') + rem;
        res[i] = '0' + (aux % 10);
        rem = aux / 10;
    }
    if(rem) res[l] = res[l] + rem + '0';
    
    
}

void fibonacci(int n){
    memset(res,0,PREC);
    if(n<=fibo_cache_count){
        memcpy(res,fibo_cache[n],PREC);
        return;
    }
    for(;fibo_cache_count<=n;fibo_cache_count++){
        memcpy(op1,fibo_cache[fibo_cache_count],PREC);
        memcpy(op2,fibo_cache[fibo_cache_count-1],PREC);
        add();
        memcpy(fibo_cache[fibo_cache_count+1],res,PREC);
    }
    memcpy(res,fibo_cache[n],PREC);

}

int main(){
    int i,j,n,f=0;
    memset(op1,0, PREC);
    memset(op2,0, PREC);
    while(scanf("%d",&n) != EOF){
        fibonacci(n);
        rev(res);
        printf("The Fibonacci number for %d is %s\n",n,res);
    }
    return 0;
}
