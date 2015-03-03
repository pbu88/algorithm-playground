#include <stdio.h>

char board[8][8];

int main(){
    int i, j, k, l;
    int valid = 1;
    int queens = 0;
    char c;
    for(i=0;i<8;i++){
        for(j=0;j<9;j++){
            scanf("%c", &c);
            if(c=='*'){
                board[i][j] = 1;
                queens++;
            }
        }
    }
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j]){
                for(k=0;k<8;k++){
                    /* horizontal */
                    if(board[i][k] && k!=j){
                        valid = 0;
                        break;
                    }
                    /* vertical */
                    if(board[k][j] && k!=i){
                        valid = 0;
                        break;
                    }
                }
                k=i+1, l=j+1;
                while(k>=0 && l>=0 && k<8 && l<8){
                    if(board[k][l]){
                        valid = 0;
                        break;
                    }
                    k++, l++;
                }
                k=i+1, l=j-1;
                while(k>=0 && l>=0 && k<8 && l<8){
                    if(board[k][l]){
                        valid = 0;
                        break;
                    }
                    k++, l--;
                }
                k=i-1, l=j+1;
                while(k>=0 && l>=0 && k<8 && l<8){
                    if(board[k][l]){
                        valid = 0;
                        break;
                    }
                    k--, l++;
                }
                k=i-1, l=j-1;
                while(k>=0 && l>=0 && k<8 && l<8){
                    if(board[k][l]){
                        valid = 0;
                        break;
                    }
                    k--, l--;
                }
            }
        }
    }
    if(valid && queens==8) printf("valid\n");
    else printf("invalid\n");
    return 0;
}
