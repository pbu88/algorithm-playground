#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string s;
    scanf("%d\n", &n);
    getline(cin, s);
    int diff = 0;
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='M' && diff==n){
            if(i+1<s.length() && s[i+1] == 'W'){
                i++;
                res+=2;
                continue;
            }
            else break;
        }
        else if(s[i]=='W' && diff==-n){
            if(i+1<s.length() && s[i+1] == 'M'){
                i++;
                res+=2;
                continue;
            }
            else break;
        }
        if(s[i]=='M'){
            diff++;
        }
        else{
            diff--;
        }
        res++;
    }
    printf("%d\n", res);
    return 0;
}
