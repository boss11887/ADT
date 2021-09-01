#include <stdio.h>

int main(){
    int new,old,c,n;
    scanf("%d %d %d %d",&new,&old,&c,&n);
    printf("%d",1000*c/(n*(old-new)) + ((1000*c)%(n*(old-new)) != 0 ) );
    return 0;
}
//2 15 150 14