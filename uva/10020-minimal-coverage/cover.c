#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x1,x2;
} point;

point points[100001];
point sol[100001];

int compare(const void* e1, const void* e2){
    point *p1 = (point*)e1;    
    point *p2 = (point*)e2;    
    if(p1->x1 != p2->x1) return p1->x1 - p2->x1;
    return p1->x2 - p2->x2;
}


int getnext(int s, int l){
    int max = points[s].x2;
    int r = -1;
    int i = s+1;
    for(;i<l;i++){
        if(points[s].x2 < points[i].x1) break;
        if(points[i].x2 > max){
            r = i;
            max = points[i].x2;
        }
    }
    return r;
}

int main(){
    int t,m,x1,x2,l,res,s,e;
    int j,i;
    scanf("%d",&t);
    while(t--){
        res = 0;
        scanf("%d",&m);
        l = 0;
        s = e = -1;
        while(1){
            scanf("%d %d",&x1, &x2);
            if(!x1 && !x2) break;
            points[l].x1 = x1;
            points[l].x2 = x2;
            l++;
        }
        qsort(points,l,sizeof(point),compare);
        s = e = 0;
        int emax_i = 0;
        for(i=0;i<l;){
            if(points[i].x2 < 0){
                i++;
                continue;
            }
            if(!s && !e){
                s = points[i].x1;
                e = points[i].x2;
                sol[res] = points[i];
                res++;
            }
            j = getnext(i,l);            
            if(j<0) break;
            if(points[j].x1<=0){
                s = points[j].x1;
                e = points[j].x2;
                i = j;
                sol[res-1] = points[i];
                continue;
            }
            e = points[j].x2;
            i = j;
            sol[res] = points[i];
            res++;
            if(e>=m) break;
        }

        if(s <= 0 && e >= m){
            printf("%d\n",res);
            for(i=0;i<res;i++){
                printf("%d %d\n",sol[i].x1, sol[i].x2);
            }
        }
        else{
            printf("0\n");
        }
        if(t!=0) printf("\n");
    }
    return 0;
}
