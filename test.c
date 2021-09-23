#include <stdio.h>

void fun(char s[4]){
    for(int a=0;a<4;a++){
        printf("%c ",s[a]);
    }
}
int main(){
    char s[]={'a','b','c','d'};
    fun(s);
}
