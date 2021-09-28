#include <stdio.h>

int main(){
int ar[100005];
int n;
scanf("%d",&n);
for(int a=1;a<=n;a++){
    scanf("%d",&ar[a]);
}
for(int i=2;i<=n;i++){
    int val = ar[i];
    int cur = i-1;
    while(cur >= 0 && ar[cur] > val){
        ar[cur+1] = ar[cur];
        cur-=1;
    }
    ar[cur+1]=val;
    for(int i=1;i<=n;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
}

return 0;}
/*
8
4 3 2 10 12 1 5 6
*/
