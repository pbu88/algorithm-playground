#include <stdio.h>

int nums[15] = {561,1105,1729,2465,2821,6601,8911,
    10585,15841,29341,41041,46657,52633,62745,63973
};

int main(){
    int n;
    int i;
    int f;
    while(1){
        scanf("%d",&n);
        if(!n) break;
        f = 0;
        for(i=0;i<15;i++){
            if(nums[i]==n){
                printf("The number %d is a Carmichael number.\n",n);
                f = 1;
                break;
            }
        }
        if(!f)
            printf("%d is normal.\n",n);
    }
    
    return 0;
}
