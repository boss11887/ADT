#include <stdio.h>

int main(){
    int a,b;
    char m;
    scanf("%d %c %d",&a,&m,&b);
    if(m=='+'){
        printf("%d",a+b);
    }else if(m=='-'){
        printf("%d",a-b);
    }else if(m=='*'){
        printf("%d",a*b);
    }else if(m=='/'){
        printf("%.2f",(float)a/b);
    }else if(m=='%'){
        printf("%d",a%b);
    }else{
        printf("Unknown Operator");
    }
}
