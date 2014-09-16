#include <stdio.h>
#include <string.h>

char src[30];
char tar[30];

char table[30][30];
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

void buildpath(int x, int y){
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
            printf("C%c%02d",tar[origy-1],origx);
            break;
        case 1:
            printf("D%c%02d",src[origx-1],origx);
            break;
        case 2: 
            printf("I%c%02d",tar[origy-1],origx+1);
            break;
        default:
            /* equals */
            x--;
            y--;
            break;
    }
    buildpath(x,y);
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
    while(1){
        scanf("%s", src);
        if(strcmp(src, "#") == 0){
            break;
        }
        scanf("%s\n", tar);
        n=strlen(src);
        m=strlen(tar);
        editdistance();
        int i,j;
        /*for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                printf("%d,",table[i][j]);
            }
            printf("\n");
        }*/
        buildpath(n,m);
        printf("E\n");
    }
    return 0;
}
