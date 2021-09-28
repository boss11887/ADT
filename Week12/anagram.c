#include <stdio.h>
#include <string.h>
char s[100005][55];
char q[100005][55];
/*
bac
*/
void sort(char *ar){
    int n=strlen(ar);
    for(int i=1;i<n;i++){
        int val = ar[i];
        int cur = i-1;
        while(cur >= 0 && ar[cur] > val){
            ar[cur+1] = ar[cur];
            cur-=1;
        }
        ar[cur+1]=val;
    }
}

int main(){
int n,m;
scanf("%d %d",&n,&m);
for(int a=0;a<n;a++){
    scanf("%s",s[a]);
    strcpy(q[a],s[a]);
    sort(s[a]);
}
for(int a=1;a<=m;a++){
    char want[55];
    scanf("%s",want);
    sort(want);
    for(int b=0;b<n;b++){
        if(!strcmp(s[b],want)){
            printf("%s ",q[b]);
        }
    }
    printf("\n");
}

return 0;}
/*
>>> test case #1
8 3
final
fnali
fnial
fianl
title
ttile
tilte
equal
fanil
reply
title
>>> test case #2
8 5
equal
tilte
porxy
stioc
sotic
prxoy
eauql
asybs
search
stoic
tilt
qual
proxy
>>> test case #3
4 4
fried
gainly
sadder
listen
fired
laying
dreads
silent
*/
