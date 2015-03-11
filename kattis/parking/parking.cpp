#include <stdio.h>

typedef struct{
    int x, y;
} point;

point points[3];

int main(){
    int prices[4];
    prices[0] = 0;
    scanf("%d %d %d", &prices[1], &prices[2], &prices[3]);
    prices[2] *= 2;
    prices[3] *= 3;
    for(int i=0;i<3;i++){
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    int res = 0;
    for(int i=1;i<=100;i++){
        int overlaps = 0;
        for(int j=0;j<3;j++){
            if(points[j].x <= i && points[j].y > i){
                overlaps++;
            }
        }
        res+=prices[overlaps];
    }
    printf("%d\n", res);
    return 0;
}
