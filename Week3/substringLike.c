#include <stdio.h>
char s[100005];
char chk[100005];

int main(){
int n,m,k,i,j;
scanf("%d %d %d",&n,&m,&k);
scanf("%s",s);
scanf("%s",chk);

for(i=0;i<n;i++){
    int cnt=0;
    int miss=0;
    for(j=0;j<m;j++){
        //printf("-%d(%d)-",i+j,n-2);
        if( (i+j) > (n-1)){
            //printf("out");
            break;
        }
        if(s[i+j]!=chk[j]){
            miss++;
            if(miss>k){
                break;
            }
        }
        if(j == m-1){
            printf("[");
            for(j=0;j<m;j++){
                if(s[i+j]==chk[j]){
                    printf("%c",s[i+j]);
                }else{
                    printf("?");
                }
            }
            printf("]");
            cnt=m-1;
        }
    }
    if(cnt==0){
        //printf("++");
        printf("%c",s[i]);
    }
    i+=cnt;
    //printf("..(%d)%d..",cnt,i);
}
return 0;}
/*
18 3 0
acabababababcbabab
aba

18 3 1
acabababababcbabab
aba

19 3 3
acabababababcbababa
aba

15 4 2
AAAGTGTGTCTGATT
GTAT
*/
