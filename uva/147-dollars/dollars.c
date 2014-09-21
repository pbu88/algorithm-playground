#include <stdio.h>

typedef long long ll;

int coins[] = {2000,1000,400,200,100,40,20,10,4,2,1};
ll dp[6001][11];

int main(){
    double aux;
    ll amount, i, j, res;
    for(j=1;j<=6000;j++){
        res = 0;
        for(i=10;i>=0;i--){
            if(j-coins[i] == 0)
                res+=1;
            if(j-coins[i] > 0)
                res+=dp[j-coins[i]][i];
            dp[j][i]=res;
        }
    }
    while(1){
        scanf("%lf", &aux);
        amount = 20*aux;
        if(!amount) break;
        printf("%6.2lf%17.lld\n", aux, dp[amount][0]);
    }
    return 0;
}
