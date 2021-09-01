#include <stdio.h>
#include <stdlib.h>

void findStats(int ar[],int n,double *avg,int *maxi,int *mini){
int *pos;
double sum=0;
for(int a=0;a<n;a++){
    sum+=ar[a];
}
//printf("..sum =%.0f..",sum);
sum/=(double)n;
*avg=sum;

int high=-100000;
for(int a=0;a<n;a++){
    if(ar[a] > high)
        high=ar[a];
}
*maxi=high;

int low=100000;
for(int a=0;a<n;a++){
    if(ar[a] < low)
        low=ar[a];
}
*mini=low;

}

int main(){
    int n,i,maxi=0,mini=0;
    double avg;
    int* nums;

    scanf("%d",&n);
    nums = (int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",nums+i);
    }
    findStats(nums,n,&avg,&maxi,&mini);
    printf("%.2f %d %d",avg,maxi,mini);
return 0;}

/*
5
1
2
3
4
1
*/
