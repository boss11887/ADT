#include <stdio.h>

int main(){
    char q,w;
    scanf("%c %c",&q,&w);
    if(q>w)
        printf("%d",q-w);
    else
        printf("%d",w-q);
    return 0;
}