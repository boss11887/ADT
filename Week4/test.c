#include <stdio.h>
#include <math.h>
int n,m,use[40];
int main(){
scanf("%d %d",&n,&m);
int nr=n,nc=m,total=0;
int chk=1;

while(nr>0){
    int cal=nr&-nr;
    use[(int)log2(cal)]=1;
    total+=m/cal;
    nr-=cal;
}
while(nc>0){
    int cal=nc&-nc;
    if(use[(int)log2(cal)])
        total--;
    total+=n/cal;
    nc-=cal;
}
printf("%d",total);
return 0;}

//Big O = log(n) + log(m)
