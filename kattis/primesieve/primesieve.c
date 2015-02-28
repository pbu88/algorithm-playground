#include <stdio.h>
#include <math.h>
 
#define UPPER_BOUND 100000000
#define MAX 50000001
#define SQRT 10002
 
typedef long long ll;
 
char sieve[MAX];
ll primes;
 
void compute_sieve(ll n){
    ll i, j;
    primes = 1;
    for(i=3;i<UPPER_BOUND && i<=n;i+=2){
        if(!sieve[i/2]){
            primes++;
            for(j=3*i;j<UPPER_BOUND;j+=(2*i)){
                sieve[j/2]=1;
            }
        }
    }
}
 
int is_prime(ll n){
    ll i;
    if(n<2) return 0;
    if(n==2) return 1;
    if(!(n%2)) return 0;
    return sieve[n/2]==0;
}
 
int main(){
    ll n, i, primesc, q;
    primesc=0;
    scanf("%lld %lld", &n, &q);
    compute_sieve(n);
    printf("%lld\n", primes);
    while(q--){
        scanf("%lld", &n);
        printf("%d\n", is_prime(n));
    }
    return 0;
}
