#include <stdio.h>
#include <string.h>

int poly1[257];
int poly2[257];
int poly3[515];

int main(){
    int t, n, n2;
    scanf("%d", &t);
    while(t--){
        memset(poly3, 0, sizeof(poly3));
        scanf("%d", &n);
        for(int i=0;i<=n;i++){
            scanf("%d", &poly1[i]);
        }
        scanf("%d", &n2);
        for(int i=0;i<=n2;i++){
            scanf("%d", &poly2[i]);
        }
        for(int i=n;i>=0;i--){
            for(int j=n2;j>=0;j--){
                poly3[i+j] += poly2[j]*poly1[i];
            }
        }
        printf("%d\n", n2+n);
        for(int i=0;i<=n2+n-1;i++){
            printf("%d ", poly3[i]);
        }
        printf("%d\n", poly3[n2+n]);
    }
    return 0;
}
