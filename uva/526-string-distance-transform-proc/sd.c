#include <stdio.h>
#include <string.h>

#define MAX 100

char src[100];
char tar[100];

char table[100][100];
int n,m;

typedef struct point{
    int x,y;
} point;

point vec[3] = {{-1,-1},{-1,0},{0,-1}};

int min(int a, int b, int c){
    int r;
    r = a < b ? a:b;
    r = r < c ? r:c;
    return r;
}

void buildpath(int x, int y, int step){
    if(x<0 || y<0) return;
    int origx,origy;
    origx = x;
    origy = y;
    int i,min=table[x][y],pos;
    int aux,action=-1;
    for(i=0;i<3;i++){
        if(origx+vec[i].x >= 0 && origy+vec[i].y >= 0){
            aux = table[origx+vec[i].x][origy+vec[i].y];
            if(min > aux){
                x = origx + vec[i].x;
                y = origy + vec[i].y;
                min = aux;
                action = i;
            }
        }
    }
    switch(action){
        case 0:
            /*printf("C%c%02d",tar[origy-1],origx);*/
            printf("%d Replace %d,%c\n",step, origx, tar[origy-1]);
            step++;
            break;
        case 1:
            /*printf("D%c%02d",src[origx-1],origx);*/
            printf("%d Delete %d\n",step , origx);
            step++;
            break;
        case 2: 
            /*printf("I%c%02d",tar[origy-1],origx+1);*/
            printf("%d Insert %d,%c\n",step ,origx+1, tar[origy-1]);
            step++;
            break;
        default:
            /* equals */
            x--;
            y--;
            break;
    }
    buildpath(x,y, step);
}

void editdistance(){
    memset(table, 0, sizeof(table));
    int i,j;
    for(i=1;i<=n;i++){
        table[i][0]=i;
    }
    for(i=1;i<=m;i++){
        table[0][i]=i;
    }
    
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(src[i-1]==tar[j-1]) table[i][j]=table[i-1][j-1];
            else table[i][j] = 
                1 + min(table[i][j-1],table[i-1][j],table[i-1][j-1]);
        }
    }
}

int main(){
    int f = 1;
    while(gets(src)){
        gets(tar);
        n=strlen(src);
        m=strlen(tar);
        editdistance();
        /*int i,j;
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                printf("%d,",table[i][j]);
            }
            printf("\n");
        }*/
        if(!f){
            printf("\n");
        }
        f=0;
        printf("%d\n",table[n][m]);
        buildpath(n,m,1);
    }
    return 0;
}
