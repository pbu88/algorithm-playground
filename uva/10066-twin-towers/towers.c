#include <stdio.h>
#include <string.h>

#define MAX 101

int text1[MAX];
int text2[MAX];
int table[MAX][MAX];

int max(int a, int b){
    return a>b? a : b;
}

int main(){
    int i,j,n,m,t=1;
    while(1){
        scanf("%d %d",&n,&m);
        if(!n && !m) break;
        for(i=0;i<n;i++) scanf("%d",&text1[i]);
        for(i=0;i<m;i++) scanf("%d",&text2[i]);
        memset(table,0,sizeof(table));
        for(i=n-1;i>=0;i--){
            for(j=m-1;j>=0;j--){
                if(text1[i]==text2[j])
                    table[i][j] = 1 + table[i+1][j+1];
                else
                    table[i][j] = max(table[i+1][j],table[i][j+1]);
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",
                t++,
                table[0][0]);
    }
    return 0;
}
