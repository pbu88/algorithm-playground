#include <stdio.h>

int main(){
    int q[1440];
    int c,n,t,m;
    int i,ans,pos;
    scanf("%d",&c);
    while(c--){
        scanf("%d %d %d",&n,&t,&m);
        for(i=0;i<m;i++){
            scanf("%d",&q[i]);
        }
        int rem = m%n;
        int div = m/n;
        if(rem){
            div++;
            ans = q[rem-1]+2*t;
            pos = rem;

        }
        else{
            ans = q[n-1]+2*t;
            pos = n;
        }
        for(;pos<m;pos+=n){
            if(ans>=q[pos+n-1]) ans=ans+2*t;
            else ans=q[pos+n-1]+2*t;
        }
        ans-=t;
        printf("%d %d\n",ans,div);
    }
    return 0;
}