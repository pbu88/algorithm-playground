#include <stdio.h>
#include <string.h>

#define MAX 250

char text1[250];
char text2[250];
int table[250][250];

int max(int a, int b){
    return a>b? a : b;
}

int main(){
    int i,j,n,m,t=1;
    while(gets(text1) && text1[0] != '#'){
        memset(table,0,sizeof(table));
        gets(text2);
        n=strlen(text1);
        m=strlen(text2);
        for(i=n-1;i>=0;i--){
            for(j=m-1;j>=0;j--){
                if(text1[i]==text2[j])
                    table[i][j] = 1 + table[i+1][j+1];
                else
                    table[i][j] = max(table[i+1][j],table[i][j+1]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",
                t++,
                table[0][0]);
    }
    return 0;
}
