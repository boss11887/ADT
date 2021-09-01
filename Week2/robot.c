#include <stdio.h>
#include <math.h>

int evencheck(int a){
    if(a%2==1)
        return 0;
    return 1;
}

int pom(int a){
    if(a <= 1)
        return 1;
    return -1;
}
char s[100005];

int main(){
    int n,i;
    scanf("%d",&n);
    scanf("%s",s);
    int north=0,east=0,state=200001;
    for(i=0;i<n;i++){
        if(s[i] == 'F'){
            if(evencheck(state%4)){
                north+=pom(state%4);
            }else{
                east+=pom(state%4);
            }
        }else if(s[i] == 'R'){
            state++;
        }else{
            state--;
        }
    }
    long long cal1=north*north;
    long long cal2=east*east;
    cal1+=cal2;
    float ans=sqrt(cal1);
    printf("%.4f",ans);
    return 0;
}

/*
gcc robot.c && ./a.out
4
RRRR
18
FFRFFRFLFRFFRFLFRF
*/
