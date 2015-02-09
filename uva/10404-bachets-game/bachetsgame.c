#include <stdio.h>

int n, m;
int D[1000001];
int R[11];

int main(){
    int i, j;
    while(scanf("%d %d", &n, &m) != EOF){
        for(i=0; i<m; i++){
            scanf("%d", &R[i]);
        }
        D[0] = 0;
        for(i=1; i<=n; i++){
            D[i] = 0;
            for(j=0; j<m; j++){
                if((i - R[j]) >= 0 && !D[i-R[j]]){
                    D[i] = 1;
                    break;
                }
            }
        }
        if(D[n]) 
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
