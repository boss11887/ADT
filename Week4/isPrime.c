#include <stdio.h>
#include <math.h>

int main(){
long long n;
scanf("%lld",&n);
if(n<=1){
    printf("0");
    return 0;
}
long long high=sqrt(n);
for(int i=2;i<=high;i++){
    if(n%i==0){
        printf("0");
        return 0;
    }
}
printf("1");
return 0;}

//Big O = sqrt(n)

