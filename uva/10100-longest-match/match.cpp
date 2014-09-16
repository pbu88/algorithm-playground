#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

vector<string> inp1;
vector<string> inp2;

int table[501][501];

bool not_char(char c){
    if(('A' <= c && c <= 'Z') ||
       ('a' <= c && c <= 'z') ||
       ('0' <= c && c <= '9'))
        return false;
    return true;
}

inline int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    string aux;
    bool blank = false;
    char c;
    int t = 1;
    while(1){
        if(scanf("%c",&c)!=EOF) cin.putback(c);
        else break;
        blank = false;
        inp1.clear();
        inp2.clear();
        memset(table,0,sizeof(table));
        for(int j=0;j<2;j++){
            getline(cin,aux);
            if(aux.size()==0) blank = true;
            replace_if(aux.begin(), aux.end(), not_char, ' ');
            char *x = (char*)aux.c_str();
            char *res;
            while(res = strtok(x," ")){
                if(j==0) inp1.push_back(res);            
                else inp2.push_back(res);
                x = NULL;
            }
        }
        int n = inp1.size()-1;
        int m = inp2.size()-1;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(inp1[i] == inp2[j]) table[i][j] = table[i+1][j+1] + 1;
                else table[i][j] = max(table[i+1][j],table[i][j+1]);
            }
        }
        if(!blank)
            printf("%2d. Length of longest match: %d\n",t++,table[0][0]);
        else printf("%2d. Blank!\n",t++);
    }
    return 0;
}
