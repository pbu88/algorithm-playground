#include <stdio.h>
#include <string.h>


#define MAX_INP 32
#define SSIZE 20

int dp[MAX_INP][SSIZE];
char inp[MAX_INP];
char* s = "welcome to code jam";


int main(){
    int n, l;
    scanf("%d\n", &n);
    for(int k=1;k<=n;k++){
        memset(dp, 0, sizeof(dp));
        gets(inp);
        l = strlen(inp);
        for(int i=0;i<=l;i++){
            dp[i][SSIZE-1] = 1;
        }
        for(int i=l-1;i>=0;i--){
            for(int j=SSIZE-2;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                if(s[j]==inp[i]){
                    dp[i][j] += dp[i+1][j+1];
                    dp[i][j] %= 1000;
                }
            }
        }
        /*for(int i=0;i<=l;i++){
            for(int j=0;j<SSIZE;j++){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }*/
        printf("Case #%d: %.4d\n", k, dp[0][0]);
    }
    return 0;
}
