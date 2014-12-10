#include <stdio.h>
#include <string.h>

#define MAX_NODES 1001

int g[MAX_NODES][MAX_NODES];
char bitmask[MAX_NODES][MAX_NODES];

int bellman_ford(int n, int m){
    int i, j;
    int d[n], p[n];
    memset(d, 0x7F, sizeof(d));
    memset(p, -1, sizeof(p));
    d[0] = 0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(bitmask[i][j] && (d[i] + g[i][j] < d[j])){
                d[j] = d[i] + g[i][j];
                p[j] = i;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(bitmask[i][j] && (d[i] + g[i][j] < d[j])){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int tc, n, m, t, i, j, a, b;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        memset(g, 0, sizeof(g));
        memset(bitmask, 0, sizeof(bitmask));
        for(i=0;i<m;i++){
            scanf("%d %d %d", &a, &b, &t);
            g[a][b] = t;
            bitmask[a][b]=1;
        }
        if (bellman_ford(n, m)) printf("possible\n");
        else printf("not possible\n");
    }
}
