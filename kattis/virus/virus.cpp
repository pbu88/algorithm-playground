#include <stdio.h>
#include <string.h>

#define MAX 100001
char line1[MAX];
char line2[MAX];

int main(){
    scanf("%s", line1);    
    scanf("%s", line2);    
    int start = 0;
    int end = 0;
    int end1 = strlen(line1);
    int end2 = strlen(line2);
    while(start < end1 && start < end2 && line1[start]==line2[start]) start++;
    while(end < end1 && end < end2 && line1[end1 - end - 1]==line2[end2 - end - 1]) end++;
    if (start + end > end1) end = end1 - start;
    int res = end2 - end - start;
    if (res > 0) printf("%d\n", res);
    else printf("0\n");
    return 0;
}
