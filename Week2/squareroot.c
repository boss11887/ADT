#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
    double ans,now,last,diff=1000,n;
    scanf("%lf %lf",&n,&now);
    while(diff>1e-10){
        ans=0.5*(now+n/now);
        diff=fabs(ans-now);
        printf("%.10f %.10f %.10f\n",ans,now,diff);
        now=ans;
    }
    printf("%.10f",ans);

    return 0;}
void fun(double now,double n){
    if(diff > 1e-10)
        return;
    ans=0.5*(now+n/now);
    diff=fabs(ans-now);
    printf("%.10f %.10f %.10f\n",ans,now,diff);
    fun(ans,n)
}