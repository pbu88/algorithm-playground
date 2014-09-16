#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string.h>
#include <ctype.h>

using namespace std;

typedef struct {
    string name;
    int points;
    int gplayed;
    int w,t,l;
    int gf,ga;
} team;

map<string, team> m;
vector<team> v;

bool pred(const team& s1, const team& s2){
    int gd1 = s1.gf - s1.ga;
    int gd2 = s2.gf - s2.ga;
    if(s1.points != s2.points){
        return s1.points > s2.points;
    }
    else if(s1.w != s2.w){
        return s1.w > s2.w;
    }
    else if(gd1 != gd2){
        return gd1 > gd2;
    }
    else if(s1.gf != s2.gf){
        return s1.gf > s2.gf;
    }
    else if(s1.gplayed != s2.gplayed){
        return s1.gplayed < s2.gplayed;
    }
    else{
        string n1=s1.name, n2=s2.name;
        transform(n1.begin(),n1.end(),n1.begin(),::tolower);
        transform(n2.begin(),n2.end(),n2.begin(),::tolower);
        return n1 < n2;
    }
}

int main(){
    int N,T,G,i,j;
    string tname,aux;
    char c1[101], c2[101];
    int g1,g2;
    scanf("%d\n",&N);
    for(i=0;i<N;i++){
        v.clear();
        m.clear();
        getline(cin,tname);
        cout << tname << endl;
        scanf("%d\n",&T);        
        for(j=0;j<T;j++){
            getline(cin,aux);
            m[aux].name = aux;
        }
        scanf("%d\n",&G);
        for(j=0;j<G;j++){
            scanf("%[^#]#%d@%d#%[^\n]\n",c1,&g1,&g2,c2);
            m[c1].gplayed++;
            m[c2].gplayed++;
            m[c1].gf+=g1;
            m[c1].ga+=g2;
            m[c2].gf+=g2;
            m[c2].ga+=g1;
            if(g1>g2){
                m[c1].w++;
                m[c2].l++;
                m[c1].points+=3;
            }
            else if(g1<g2){
                m[c2].w++;
                m[c1].l++;
                m[c2].points+=3;
            }
            else{
                m[c1].t++;
                m[c2].t++;
                m[c1].points++;
                m[c2].points++;
            }
        }
        map<string,team>::iterator pos;
        for(pos=m.begin();pos!=m.end();pos++){
            v.push_back(pos->second);
        }
        sort(v.begin(),v.end(),pred);
        for(j=0;j<v.size();j++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    j+1,
                    v[j].name.c_str(),
                    v[j].points,
                    v[j].gplayed,
                    v[j].w,
                    v[j].t,
                    v[j].l,
                    v[j].gf - v[j].ga,
                    v[j].gf,
                    v[j].ga);

        }
        if(i<N-1) printf("\n");
    }
    return 0;
}
