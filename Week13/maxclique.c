#include <stdio.h>

int store[30], n,m;
int graph[30][30];

int max(int a,int b){
    if(a > b)
        return a;
    return b;
}

int is_clique(int b)
{
    for (int i = 1; i < b; i++) {
        for (int j = i + 1; j < b; j++)
            if (graph[store[i]][store[j]] == 0)
                return 0;
    }
    return 1;
}

int maxCliques(int i, int l)
{
    int max_ = 0;
    for (int j = i + 1; j <= n; j++) {
        store[l] = j;
        if (is_clique(l + 1)) {
            max_ = max(max_, l);
            max_ = max(max_, maxCliques(j, l + 1));
        }
    }
    return max_;
}

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=0;i<m;i++) {
        int st,ed;
        scanf("%d %d",&st,&ed);
        graph[st+1][ed+1] = 1;
        graph[ed+1][st+1] = 1;
    }

    printf("%d",maxCliques(0, 1));

    return 0;
}
/*
2. maxClique
>>> test case #1
5 5
1 2
2 0
0 1
0 3
3 4
>>> test case #2
5 8
0 1
0 3
0 2
1 3
1 2
2 3
3 4
2 4
>>> test case #3
7 12
0 1
0 2
0 3
1 3
2 4
2 5
2 6
3 4
3 5
4 5
4 6
5 6
>>> test case #4
10 18
8 0
9 8
3 9
0 3
3 4
2 4
1 0
1 2
5 6
6 7
2 5
5 7
4 7
1 3
4 0
2 3
1 4
0 2
>>> test case #5
6 9
0 1
0 2
1 2
1 3
1 4
3 4
2 4
2 5
4 5
----------
*/
