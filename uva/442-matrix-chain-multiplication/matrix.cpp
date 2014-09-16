#include <stdio.h>
#include <map>
#include <string>
#include <stack>
#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

typedef struct {
    int row,col;
} matrix;

map<char,matrix> m;
stack<matrix> s;

int main(){
    int n,i;
    ll res;
    char name;
    int row,col;
    char exp[1000];
    scanf("%d\n",&n);
    while(n--){
        scanf("%c %d %d\n",&name,&row,&col);
        matrix aux;
        aux.row = row;
        aux.col = col;
        m[name] = aux;
    }
    while(scanf("%s",exp) != EOF){
        while(!s.empty()) s.pop();
        res = 0;
        int l = strlen(exp);
        for(i=0;i<l;i++){
            if(exp[i]==')'){
                matrix m2 = s.top();                
                s.pop();
                matrix m1 = s.top();
                s.pop();
                if(m1.col != m2.row){
                    printf("error\n");
                    res = -1;
                    break;
                }
                res+=m1.row*m1.col*m2.col;
                matrix m3;
                m3.row = m1.row;
                m3.col = m2.col;
                s.push(m3);
            }
            else if(exp[i]!='('){
                s.push(m[exp[i]]);
            }
        }
        if(res<0) continue;
        printf("%lld\n",res);
    }
    return 0;
}
