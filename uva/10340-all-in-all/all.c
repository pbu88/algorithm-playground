#include <stdio.h>
#include <string.h>

char S[1000001];
char T[1000001];

int main(){
    int i,j,lt,ls;
    while(scanf("%s %s", S, T) != EOF){
        lt = strlen(T);
        ls = strlen(S);
        j = 0;
        for(i=0;i<lt;i++){
            if(T[i] == S[j]){
                j++;
                if(j==ls) break;
            }
        }
        if(j==ls) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
