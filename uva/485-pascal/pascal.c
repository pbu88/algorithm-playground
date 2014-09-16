
#include <stdio.h>
#include <string.h>

#define PREC 1000

char op1[PREC];
char op2[PREC];
char res[PREC];

char pascal_r[PREC][PREC];

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

void pascal_row(int n){
    if(n==1){
        memcpy(pascal_r[0],"1",2);
        return;
    }
    char raux[PREC][PREC];
    memcpy(raux,pascal_r,sizeof(pascal_r));
    memset(pascal_r,0,sizeof(pascal_r));
    memcpy(pascal_r[0],"1",2);
    int j;
    for(j=1;j<n;j++){
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
}

int main(){
    memset(op1,0, PREC);
    memset(op2,0, PREC);
    int i,j;
    int top = 205;
    for(i=1;i<=top;i++){
        pascal_row(i);
        printf("%s",pascal_r[0]);
        for(j=1;j<i;j++){
            rev(pascal_r[j]);
            printf(" %s",pascal_r[j]);
            rev(pascal_r[j]);
        }
        printf("\n");
    }
    return 0;
}
