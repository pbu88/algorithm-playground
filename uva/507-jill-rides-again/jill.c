#include <stdio.h>

typedef struct {
    int lenght, left, right;
} dp_t;

int seq[30000];

int main(){
    int r, c, i, j, left, right, max, sum, longest, id=0;
    scanf("%d", &r);
    while(r--){
        id++;
        scanf("%d", &c);
        for(i=0;i<c-1;i++){
            scanf("%d", &seq[i]);
        }
        sum=0;
        max=-1;
        left=0;
        right=0;
        j=0;
        for(i=0;i<c-1;i++){
            sum+=seq[i];
            if(sum > max || (sum==max && longest<(i+1-j))){
                max = sum;
                left=j;
                right=i+1;
                longest=right-left;
            }
            if(sum<0){
                sum=0;
                j=i+1;
            }
        }
        if(max>0){
            printf("The nicest part of route %d is between stops %d and %d\n", id, left+1, right+1);
        }
        else{
            printf("Route %d has no nice parts\n", id);
        }
    }
}
