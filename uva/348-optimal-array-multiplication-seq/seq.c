#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

typedef struct{
    int row, col;
} matrix;

matrix v[11];
int cache[11][11];
int path[11][11];
int l;

inline int min(int a, int b){
    return a < b? a : b;
}

string outp(int s, int n){
    string res;
    if(s==n){
        char buf[4];        
        sprintf(buf,"A%d",s);
        res = buf;
        return res;
    }
    res = "("+outp(s,path[s][n]) +" x " + outp(path[s][n]+1,n)+")";
    return res;
}

void ans(int n){
    int i,j,k;
    int min;
    memset(cache,0,sizeof(int)*11*11);
    memset(path,0,sizeof(int)*11*11);
    for(j=1;j<=n;j++){
        for(i=1;i+j<=n;i++){
            min = 0x7FFFFFFF;
            for(k=i;k<=i+j-1;k++){
                int q = cache[i][k] + cache[k+1][i+j] +
                        v[i].row * v[k].col * v[i+j].col;
                if(q<min){
                    min = q;
                    path[i][i+j] = k;
                    cache[i][i+j] = q;
                }
            }
        }
    }
}

int main(){
    int n,i,cases=0;
    while(1){
        cases++;
        scanf("%d",&n);
        if(!n) break;
        l = n;
        for(i=1;i<=n;i++){
            scanf("%d %d",&v[i].row, &v[i].col);
        }
        ans(n);
        cout << "Case "<< cases <<": "<< outp(1,n) << endl;
    }
    return 0;
}
