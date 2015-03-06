#include <stdio.h>
#include <string.h>

#define SIZE 20000

int rows[SIZE];
int cols[SIZE];
int diag1[2*SIZE+1];
int diag2[2*SIZE+1];

int main(){
    int X, Y, n, x, y, res;
    while(1){
        scanf("%d %d %d", &X, &Y, &n);
        if(!(X+Y+n)) break;
        res = 0;
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(diag1, 0, sizeof(diag1));
        memset(diag2, 0, sizeof(diag2));
        while(n--){
            scanf("%d %d", &x, &y);
            x--, y--;
            rows[x]++, cols[y]++, diag1[x+y]++, diag2[Y+x-y]++;
        }
        for(x=0;x<X;x++)
            for(y=0;y<Y;y++){
                if(!rows[x] && !cols[y] && !diag1[x+y] && !diag2[Y+x-y]){
                    res++;
                }
            }
        printf("%d\n", res);
    }
    return 0;
}
