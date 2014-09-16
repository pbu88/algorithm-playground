/* Recurrence: C1 = 2, Cn = Cn-1 + 2*(n-1)
 * Closed form: Cn = 2 + n(n+1)
 * Especial case: C0 = 1
 */


#include <stdio.h>
#include <string.h>

#define PREC 1000

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

void sub1(){
    int i;
    int l = strlen(op1);
    memcpy(res,op1,PREC);
    for(i=0;i<l;i++){
        if(op1[i] != '0'){
            res[i] = ((op1[i] - '0') - 1) + '0';
            break;
        }
        else{
            res[i] = '9';
        }
    }
    if(res[l-1] == '0') res[l-1] = 0;
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

int main(){
    int n;
    while(scanf("%s",op1) != EOF){
        if(strcmp(op1,"0")==0){
            printf("%d\n",1);
            continue;
        }
        rev(op1);
        sub1();
        memcpy(op2,res,PREC);
        mult();
        memcpy(op2,res,PREC);
        set_op1(2);
        add();
        rev(res);
        printf("%s\n",res);

    }
    return 0;
}




