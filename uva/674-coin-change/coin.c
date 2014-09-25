#include <stdio.h>

#define SIZE 7490
#define COINS 5

typedef long long ll;

int coins[] = {50,25,10,5,1};
ll dp[SIZE][5];

int main(){
    int aux, i, j;
    ll res;
    for(j=1;j<=SIZE-1;j++){
        res = 0;
        for(i=COINS-1;i>=0;i--){
            if(j-coins[i] == 0)
                res+=1;
            if(j-coins[i] > 0)
                res+=dp[j-coins[i]][i];
            dp[j][i]=res;
        }
    }
    while(scanf("%d", &aux) != EOF){
        if(!aux) printf("1\n");
        else printf("%lld\n", dp[aux][0]);
    }
    return 0;
}
