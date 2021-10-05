#include <stdio.h>
int q[1005];
int pos=0,n,m;
int st[1005],ed[1005];
int ar[1005][1005];
int visit[1005];
int ms[1005];
int val=1;

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}
void dfs(int now){
    st[now]=val;
    val++;
    visit[now]=1;
    for(int a=0;a<n;a++){
        if(ar[now][a]==1){
            if(visit[a] == 1)
                continue;
            dfs(a);
        }
    }
    ed[now]=val;
    val++;
}

int dfs2(int now,int pos){
    ms[pos]=now;
    //printf("(%d) ",now);
    visit[now]=0;
    for(int a=0;a<n;a++){
        if(ar[a][now]==1){
            if(visit[a] == 0)
                continue;
            return dfs2(a,pos+1)+1;
        }
    }
    return 0;
}

int main(){
scanf("%d %d",&n,&m);
for(int a=1;a<=m;a++){
    int st,ed;
    scanf("%d %d",&st,&ed);
    ar[st][ed]=1;
}

for(int a=0;a<n;a++){
    if(visit[a]==0){
        dfs(a);
    }
}

int ans=-1;
int realans[1005];
while(1){
    int high=-10;
    int wantpos=-1;
    for(int a=0;a<n;a++){
        if(visit[a]==1 && ed[a] > high){
            high=ed[a];
            wantpos=a;
        }
    }
    if(wantpos==-1){
        break;
    }
    int v=dfs2(wantpos,1);
    if(v > ans){
        ans=v;
        ans=max(ans,v);
        for(int a=1;a<=ans+1;a++){
            realans[a]=ms[a];
        }
    }
}

for(int a=1;a<=ans+1;a++){
    for(int b=a+1;b<=ans+1;b++){
        if(realans[a]>realans[b]){
            int tmp = realans[a];
            realans[a]=realans[b];
            realans[b]=tmp;
        }
    }
}
for(int a=1;a<=ans+1;a++){
    printf("%d ",realans[a]);
}
return 0;}
/*
3. scc
>>> test case #1
5 5
1 0
2 1
0 2
0 3
3 4
>>> test case #2
8 9
0 1
1 2
2 3
2 4
3 0
4 5
5 6
6 4
6 7
>>> test case #3
12 17
0 1
1 2
1 3
1 4
2 5
4 1
4 5
4 6
5 7
5 2
6 7
6 9
7 10
8 6
9 8
10 11
11 9
>>> test case #4
4 5
0 1
1 2
2 0
2 3
0 3
>>> test case #5
10 14
0 1
0 4
2 0
2 9
3 2
5 3
5 7
6 1
6 7
7 8
7 0
8 4
8 6
9 5
*/
