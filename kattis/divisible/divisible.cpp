#include <stdio.h>
#include <string.h>

typedef long long ll;

int D[1000001];

int main(){
    int c, d, n, elem;
    ll aux;
    scanf("%d", &c);
    while(c--){
        aux = 0;
        memset(D, 0, sizeof(D));
        D[0]++;
        int res = 0;
        scanf("%d%d", &d, &n);
        for(int i=0;i<n;i++){
            scanf("%d", &elem);
            aux += elem;
            D[aux%d]++;
        }
        for(int i=0;i<d;i++){
            res+=D[i]*(D[i]-1)/2;
        }
        printf("%d\n", res);
    }
    return 0;
}
