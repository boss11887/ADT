#include <stdio.h>

int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int a,b,c;
    scanf("%d/%d/%d",&a,&b,&c);
    b--;
    int i,ans=0;
    for(i=0;i<b;i++){
        ans+=month[i];
    }
    ans+=a;
    if(b>=2){
        if (c % 4 == 0) {
            if (c % 100 == 0) {
                if (c % 400 == 0){
                    ans++;
                }
            }else{
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
//01/01/1994
//31/12/1994
//31/12/1996
//21/02/2000