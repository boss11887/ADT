#include <stdio.h>

int main(){
    int q,w;
    scanf("%d %d",&q,&w);
    printf("%d %d",(q+w)/24,(q+w)%24);
    return 0;
}