#include <stdio.h>
#include <string.h>

#define PREC 2000

char op1[PREC];
char op2[PREC];
char res[PREC];

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

void fibonacci(int n){
    memset(res,0,PREC);
    if(n<=1){
        memcpy(res,"1",2);
    }
    op1[0] = '0', op1[1] = 0;
    op2[0] = '1', op2[1] = 0;
    int i;
    for(i=2;i<=n;i++){
        add();
        memcpy(op1,op2,PREC);
        memcpy(op2,res,PREC);
    }
}

int main(){
    int i,n;
    memset(op1,0, PREC);
    memset(op2,0, PREC);
    while(scanf("%d",&n)!=EOF){
        fibonacci(n+2);
        rev(res);
        printf("%s\n",res);
    }
    return 0;
}
