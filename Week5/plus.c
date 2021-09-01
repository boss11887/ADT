#include <stdio.h>
#include <stdlib.h>
char s1[100005],s2[100005];
int ans[100005];
int high,next=0;

void fl(int pos1,int pos2,int m){
    for(int a=high-1;a>=0;a--){
    int low,cur=0;
    if(m > 0){
        if(a-m>=0)
            cur=s1[a]-'0'+s2[a-m]-'0';
        else
            cur=s1[a]-'0';
    }else{
        if(a+m>=0)
            cur=s1[a+m]-'0'+s2[a]-'0';
        else
            cur=s2[a]-'0';
    }
    cur+=next;
    if(cur>=10){
        next=1;
        cur-=10;
    }else{
        next=0;
    }
    ans[a]=cur;
    }
    if(next==1)
        printf("1");
}

int main(){
int cnt1=0,cnt2=0;
scanf("%s %s",s1,s2);
for(int a=0;s1[a] != '\0';a++){
    cnt1++;
}
for(int a=0;s2[a] != '\0';a++){
    cnt2++;
}
int df=cnt1-cnt2;
if (df < 0)
    high = cnt2;
else
    high = cnt1;
fl(cnt1,cnt2,df);

for(int a=0;a<high;a++){
    printf("%d",ans[a]);
}
return 0;}
