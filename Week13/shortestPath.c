#include <stdio.h>

int min(int a,int b){
    if (a<b)
        return a;
    return b;
}
int ar[10005][10005];

int main(){
int n,m,p;
scanf("%d %d %d",&n,&m,&p);

for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
        if(a==b){
            ar[a][b]=0;
        }else{
            ar[a][b]=2e8;
        }
    }
}
for(int a=1;a<=m;a++){
    int st,ed,w;
    scanf("%d %d %d",&st,&ed,&w);
    ar[st][ed]=w;
    ar[ed][st]=w;
}
for(int a=0;a<n;a++){
    for(int b=0;b<n;b++){
        for(int c=0;c<n;c++){
            ar[b][c]=min(ar[b][c],ar[b][a]+ar[a][c]);
        }
    }
}

while(p--){
    int st,ed;
    scanf("%d %d",&st,&ed);
    if(ar[st][ed]==2e8)
        printf("-1\n");
    else
        printf("%d\n",ar[st][ed]);
}
return 0;}
/*
1. shortestPath
>>> test case #1
7 7 7
0 4 12
1 0 12
2 1 12
2 3 12
3 6 20
6 5 40
5 0 30
0 6
0 4
2 5
5 2
3 4
5 3
1 6
>>> test case #2
4 5 8
0 1 6
1 3 1
1 2 4
2 0 3
3 2 1
0 0
0 3
1 2
2 0
2 3
3 1
3 2
3 0
>>> test case #3
7 9 7
0 5 14
0 2 9
0 1 7
5 2 2
1 2 10
1 3 15
2 3 11
4 5 9
3 4 6
0 4
0 3
1 5
1 4
2 4
3 5
3 0
>>> test case #4
8 11 10
0 1 1
0 2 2
1 2 1
1 3 3
1 4 2
2 3 1
2 4 2
3 4 4
3 5 3
4 5 3
6 7 10
0 6
6 7
1 5
3 7
2 5
1 4
6 5
4 0
5 3
0 5
*/
