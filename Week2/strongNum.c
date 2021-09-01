#include <stdio.h>

int main(){
    int n,i,tt;
    scanf("%d",&tt);
    for(i=0;i<tt;i++){
        scanf("%d",&n);
        if(n>40585){
            printf("40585");
        }else if(n>145){
            printf("145");
        }else if(n>2){
            printf("2");
        }else{
            printf("1");
        }
    }
    return 0;
}