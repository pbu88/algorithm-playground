#include <stdio.h>

#define SIZE 1000002

int buff[SIZE];

int main(){
    int t, n, i, curr, res;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=1;i<=n;i++){
            scanf("%d", &buff[i]);
        }
        curr = 1;
        res = 0;
        for(i=1;i<=n;i++){
            if(buff[i]!=curr){
                res++;
            }
            else{
                curr++;
            }
        }
        printf("%d\n", res);
    }
}
