#include <stdio.h>
#include <string.h>

typedef long long ll;

char chars[] = {'0','1','2','3','4','5','6','7','8','9',
              'A','B','C','D','E','F'};
char res[100];
char inp[20];

int rev(char v[]){
    int i;
    int l = strlen(v);
    for(i=0;i<l-i;i++){
        char aux = v[i];
        v[i] = v[l-i-1];
        v[l-i-1] = aux;
    }
    return l;
}

int main(){
    int i,l,impossible;
    ll b1,b2,b10,b1e = 1,b2e = 1;
    while(scanf("%lld %lld %s",&b1,&b2,inp) != EOF){
        b10 = 0;
        impossible = 0;
        b1e = b2e = 1;
        l=rev(inp);
        memset(res,0,100);
        for(i=0;i<l;i++){
            char aux;
            if(inp[i] >= 'A') aux = (inp[i] - 'A' + 10);
            else aux = (inp[i] - '0');
            if(aux >= b1){
                impossible = 1;
                break;
            }
            b10 += aux*b1e;
            b1e*=b1;
        }
        if(impossible){
            rev(inp);
            printf("%s is an illegal base %lld number\n",inp,b1);
            continue;
        }
        i=0;
        if(b10 != 0){
            while(b10){
                res[i] = chars[b10%b2];
                b10/=b2;
                i++;
            }
        }
        else res[0] = '0';
        rev(res);
        rev(inp);
        printf("%s base %lld = %s base %lld\n",
                inp,b1,res,b2);
    }
    return 0;
}
