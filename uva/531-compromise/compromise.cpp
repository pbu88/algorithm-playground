#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

vector<string> text1;
vector<string> text2;
int table[100][100];
vector<string> outpv;

inline int max(int a, int b){
    return a>b? a : b;
}

void outp(int i, int j){
    if(i==text1.size() || j == text2.size()) return;
    if(text1[i]==text2[j]){
        outpv.push_back(text1[i]);
        outp(i+1,j+1);
    }
    else{
        if(table[i+1][j] > table[i][j+1])
            outp(i+1,j);
        else
            outp(i,j+1);
    }

}

int main(){
    int i,j;
    string aux;
    char c;
    while(1){
        if(cin >> c)
            cin.putback(c);
        else
            break;
        text1.clear();
        text2.clear();
        outpv.clear();
        memset(table,0,sizeof(table));
        while(1){
            cin >> aux;
            if(aux=="#") break;
            text1.push_back(aux);
        }
        while(1){
            cin >> aux;
            if(aux == "#") break;
            text2.push_back(aux);
        }
        for(i=text1.size()-1;i>=0;i--){
            for(j=text2.size()-1;j>=0;j--){
                if(i==text1.size()-1 && j==text2.size()-1){
                    table[i][j] = 
                        text1[i] == text2[j]? 1 : 0;
                }
                else if(i==text1.size()-1){
                    table[i][j] = 
                        text1[i] == text2[j]? 1 : table[i][j+1];
                }
                else if(j==text2.size()-1){
                    table[i][j] = 
                        text1[i] == text2[j]? 1 : table[i+1][j];
                }
                else{
                    if(text1[i]==text2[j])
                        table[i][j] = 1 + table[i+1][j+1];
                    else
                        table[i][j] = max(table[i+1][j],table[i][j+1]);
                }
            }
        }
        outp(0,0);
        for(i=0;i<outpv.size();i++){
            if(i) cout << " ";
            cout << outpv[i];
        }
        cout << endl;
    }
    return 0;
}
