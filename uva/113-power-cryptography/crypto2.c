#include <stdio.h>
#include <math.h>

int main(){
    double n,p;
    while(2==scanf("%lf %lf",&n,&p)){
        double r = pow(p,1/n);
        printf("%1.0f\n",r);
    }
    return 0;
}
