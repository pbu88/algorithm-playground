#include <stdio.h>
#include <math.h>

int main(){
    double d;
    scanf("%lf",&d);
    printf("%lf\n",d);
    double r = pow(d,1/50.0);
    printf("%f\n",r);
}
