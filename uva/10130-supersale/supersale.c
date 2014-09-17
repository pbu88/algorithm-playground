#include <stdio.h>
#include <string.h>

typedef struct {
    int value, weight;
} product;


int max(int a, int b){
    return a > b ? a : b;
}

product products[1001];
int strengths[101];
int dp[1001][31];
int main(){
    int t, n, i, j, p, k, strength, res;
    scanf("%d", &t);
    while(t--){
        res = 0;
        scanf("%d", &n);
        for(i=1;i<=n;i++){
            scanf("%d %d", &products[i].value, &products[i].weight);
        }
        scanf("%d", &p);
        for(i=0;i<p;i++){
            scanf("%d", &strengths[i]);
        }
        for(k=0;k<p;k++){
            memset(dp, 0, sizeof(dp));
            strength=strengths[k];
            for(i=1;i<=n;i++){
                for(j=1;j<=strength;j++){
                    if(products[i].weight <= j){
                        dp[i][j] = max(dp[i-1][j], 
                                       dp[i-1][j-products[i].weight] + products[i].value);
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            res += dp[n][strength];
        }
        printf("%d\n", res);
    }
    return 0;
}
