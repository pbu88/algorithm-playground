#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char seq[101];
    int inversions;
    int i;
} dna;

dna buff[101];


void bubble_sort(int index){
    int i,j,res=0;
    int l = strlen(buff[index].seq);
    char lbuff[101];
    memcpy(lbuff,buff[index].seq,l+1);
    for(i=0;i<l;i++){
        for(j=l-1;j>i;j--){
            if(lbuff[j] < lbuff[j-1]){
                lbuff[j] ^= lbuff[j-1];
                lbuff[j-1] ^= lbuff[j];
                lbuff[j] ^= lbuff[j-1];
                res++;
            }
        }
    }
    buff[index].inversions = res;
}


int compare(const void* a, const void* b){
    dna* a1 = (dna*)a;
    dna* b1 = (dna*)b;
    if(a1->inversions == b1->inversions){
        return strcmp(a1->seq,b1->seq);
    }
    return a1->inversions - b1->inversions;
}

int main(){
    int n,m,i,j,ft=0;
    while(1){
        scanf("%d %d",&n,&m);
        if(!n && !m) break;
        if(ft) 
            printf("\n");
        else
            ft = 1;
        for(j=0;j<m;j++){
            scanf("%s", buff[j].seq);
            buff[j].i = j;
            bubble_sort(j);
        }
        qsort(buff,m,sizeof(dna),compare);
        for(i=0;i<m;i++){
            printf("%s\n",
                    buff[i].seq);
        }
    }
    return 0;
}
