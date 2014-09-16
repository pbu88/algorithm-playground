#include <stdio.h>
#include <string.h>

#define PREC 1000

char op1[PREC];
char op2[PREC];
char MAX[PREC];
char res[PREC];

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

int pow_(){
    char base[PREC], exp[PREC], r[PREC];
    memcpy(base,op1,PREC);    
    memcpy(exp,op2,PREC);
    /*printf("base:%s exp:%s\n",base, exp);*/
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

        memcpy(op1,MAX,PREC);        
        memcpy(op2,r,PREC);
        if(cmp() < 0){
            /*printf("compare max:%s with r: %s\n",MAX,op2);*/
            return 0;
        }

        memcpy(base,res,PREC);
        memcpy(op1,exp,PREC);
        divide_by(2);
        memcpy(exp,res,PREC);
        memcpy(op1,exp,PREC);
        set_op(op2,0);
    }    
    memcpy(res,r,PREC);
    return 1;
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

int main(){
    char p[PREC];
    char exp[PREC];
    int i,j,middle;
    memset(p,0, PREC);
    memset(exp,0, PREC);
    while(scanf("%s",exp)!=EOF){
        int max = 1e9;
        int min = 1;
        scanf("%s",p);
        rev(p);
        rev(exp);
        memcpy(MAX,p,PREC);
        while(max>=min){
            middle = (max+min)/2;
            /*printf("middle = %d interval: %d - %d\n",middle, min,max);*/
            set_op(op1,middle);
            memcpy(op2,exp,PREC);
            if(!pow_()){
                max = middle-1;
                continue;
            }
            else{
                memcpy(op1,p,PREC);
                memcpy(op2,res,PREC);
                int aux = cmp();
                if(aux == 0){
                    break;
                }
                else if(aux>0){
                    min = middle + 1;
                }
                else max = middle - 1;
            }
        }
        rev(res);
        printf("%d\n",middle);
    }
    return 0;
}




