#include <stdio.h>

double cs_students[200001];
double e_students[200001];

int main(){
    int T;
    int cs, e;
    double aux, a1, a2;
    scanf("%d", &T);
    while(T--){
        a1 = a2 = 0;
        scanf("%d%d", &cs, &e);
        for(int i=0;i<cs;i++){
            scanf("%lf", &aux);
            a1 += aux;
            cs_students[i]=aux;
        }
        a1 = a1 / cs;
        for(int i=0;i<e;i++){
            scanf("%lf", &aux);
            a2 += aux;
            e_students[i]=aux;
        }
        a2 = a2 / e;
        int r = 0;
        for(int i=0;i<cs;i++){
            if(cs_students[i]<a1 && cs_students[i]>a2) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}
