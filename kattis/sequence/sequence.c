#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    int res = (int)log2(n) + 1;
    printf("%d\n", res);
    for(int i=0;i<res;i++){
        if(i<res-1){
            printf("%d ", (int)pow(2,i));
        }
        else{
            printf("%d\n", (int)pow(2,i));
        }
    }
    return 0;
}
