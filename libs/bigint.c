#include <stdio.h>
#include <string.h>

#define PREC 1000

char op1[PREC];
char op2[PREC];
char res[PREC];

char pascal_r[PREC][PREC];
char fibo_cache[PREC][PREC] = {"0","1"};
int fibo_cache_count = 1;

int is_even(char op[]){
    return op[0] == '0' || op[0] == '2' ||
           op[0] == '4' || op[0] == '6' ||
           op[0] == '8';
}

int cmp(){
    int l1 = strlen(op1);
    int l2 = strlen(op2);
    int i;
    if (l1!=l2) return l1-l2;
    for(i=l1-1; i>=0;i--){
        int aux = (op1[i] - '0') - (op2[i] - '0');
        if(aux != 0) return aux;

    }
    return 0;
}

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

set_op(char op[],int n){
    if(n==0){
        memcpy(op,"0",2);
    }
    int i = 0;
    while(n){
        op[i++] = n%10+'0';
        n/=10;
    }
    op[i] = 0;
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

void mult(){
    char op1aux[PREC];
    char op2aux[PREC];
    memcpy(op1aux, op1, PREC);
    memcpy(op2aux, op2, PREC);
    op2[0] = '0';
    op2[1] = 0;
    int i,j,k;
    int li = strlen(op1aux);    
    int lj = strlen(op2aux);    
    int rem;
    for(i=0;i<li;i++){
        memset(op1,0,PREC);
        rem = 0;
        for(k=0;k<i;k++){
            op1[k] = '0';
        }
        for(j=0;j<lj;j++){
            int aux = (op1aux[i] - '0') * (op2aux[j] - '0') + rem;
            rem = aux / 10;
            op1[i+j] = (aux % 10) + '0';
        }
        if(rem){
            op1[i+j] = rem + '0';
            j++;
        }
        op1[i+j] = 0;
        add();
        memcpy(op2,res,PREC);
    }
}

void sub(){

}

void pow_(){
    char base[PREC], exp[PREC], r[PREC];
    memcpy(base,op1,PREC);    
    memcpy(exp,op2,PREC);
    memcpy(r,"1",2);
    memcpy(op1,op2,PREC);
    set_op(op2,0);
    while(cmp() > 0){
        if(!is_even(exp)){
            memcpy(op1,r,PREC);
            memcpy(op2,base,PREC);
            mult();
            memcpy(r,res,PREC);
        }
        memcpy(op1,base,PREC);
        memcpy(op2,base,PREC);
        mult();
        memcpy(base,res,PREC);
        memcpy(op1,exp,PREC);
        divide_by(2);
        memcpy(exp,res,PREC);
        memcpy(op1,exp,PREC);
        set_op(op2,0);
    }    
    memcpy(res,r,PREC);
    set_op(op2,0);
}

int divide_by(int n){
    rev(op1);
    memset(res,0,PREC);
    int i,d = 0,rem = 0;
    int j = 0;
    int l = strlen(op1);
    char ftime = 1;
    for(i=0;i<l;i++){
        d = d*10 + (op1[i] -'0');
        if(d<n){
            if(!ftime){
                res[j++]='0';
            }
            continue;
        }
        ftime = 0;
        rem = d%n;
        int aux = d/n;
        res[j++] = aux + '0';
        d = rem;
    }
    rev(res);
}

void factorial(int n){
    memset(res,0,PREC);
    if(n<=1){
        memcpy(res,"1",2);
        return;
    }
    memcpy(op2,"1",2);
    int i;
    for(i=2;i<=n;i++){
        set_op1(i);
        mult();
        memcpy(op2,res,PREC);
    }
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

void catalan(int n){
    if(n<=1){
        memcpy(res,"1",2);
        return;
    }
    catalan(n-1);
    int m = n-1;
    int aux = 2*(2*m+1);
    set_op1(aux);
    memcpy(op2,res,PREC);
    mult();
    memcpy(op1,res,PREC);
    divide_by(m+2);
}

void pascal_row(int n){
    if(n==1){
        memcpy(pascal_r[0],"1",2);
        return;
    }
    char raux[PREC][PREC];
    memset(raux,0,sizeof(raux));
    memset(pascal_r,0,sizeof(raux));
    memcpy(raux[0],"1",2);
    int i,j;
    for(i=2;i<=n;i++){
        memcpy(pascal_r[0],"1",2);
        for(j=1;j<i;j++){
            if(!raux[j]){
                memcpy(res,raux[j-1],PREC);
            }
            else{
                memcpy(op1,raux[j-1],PREC);
                memcpy(op2,raux[j],PREC);
                add();
            }
            memcpy(pascal_r[j],res,PREC);
        }
        memcpy(raux,pascal_r,sizeof(raux));
    }
}

int main(){
    int i,j,n,f=0;
    memset(op1,0, PREC);
    memset(op2,0, PREC);
    scanf("%s %s",op1,op2);
    rev(op1);
    rev(op2);
    printf("%d\n",cmp());
    return 0;
}










