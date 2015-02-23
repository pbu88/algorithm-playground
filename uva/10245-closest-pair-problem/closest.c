#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} point;


point points[100001];
char outp[4096];

int compare(const void* e1, const void* e2){
    point *p1 = (point*)e1;    
    point *p2 = (point*)e2;    
    return p1->x - p2->x;
}

double distance(point p1, point p2){
    double x = pow(p2.x - p1.x, 2);
    double y = pow(p2.y - p1.y, 2);
    return sqrt(x + y);

}

int main(){
    int n, i, j;
    point aux, aux2, res1, res2;
    double dist, daux;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        for(i=0; i<n; i++){
            scanf("%lf %lf", &aux.x, &aux.y);
            points[i] = aux;
        }
        qsort(points, n, sizeof(point), compare);
        /*for(i=0;i<n;i++){
            printf("%f %f\n", points[i].x, points[i].y);
        }
        printf("\n");*/
        if(n>=2){
            res1 = aux = points[0];
            res2 = aux2 = points[1];
            dist = distance(aux, aux2);
            for(i=2; i<n; i++){
                aux = points[i];
                for(j=i-1; j>=0; j--){
                    aux2 = points[j];
                    daux = distance(aux, aux2);
                    if(daux < dist){
                        dist = daux;
                        res1 = aux2;
                        res2 = aux;
                    }
                    else if((aux.x - aux2.x) > dist){
                        break;
                    }
                }
            }
        }
        else{
            dist = 100000;
        }
        if(dist>=10000) printf("INFINITY\n");
        else printf("%.4lf\n", dist);
    }

    return 0;
}
