#include <stdio.h>
#include <string.h>

#define PREC 10000

char op1[PREC];
char op2[PREC];
char res[PREC];

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

int main(){
    int i,n;
    memset(op1,0, PREC);
    memset(op2,0, PREC);
    while(scanf("%d",&n) != EOF){
        catalan(n);
        rev(res);
        printf("%s\n",res);
    }
    return 0;
}
