#include <stdio.h>

typedef struct{
    int bitterness, sourness;
} ingredient;

ingredient ingredients[11];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &ingredients[i].sourness, &ingredients[i].bitterness);
    }
    int r = ingredients[n-1].

    return 0;
}
