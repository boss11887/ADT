#include <stdio.h>
char ar[10005][10005],junk,n,jue;
int visit[10005][10005];
int finr,finc;
int pr[]={1,0,-1,0};
int pc[]={0,1,0,-1};

void traverseMaze(int row,int col){

if(row > n || col > n || row == 0 || col == 0)
    return;
if(ar[row][col] == '#')
    return;

if(ar[row][col] == 'G'){
    jue=1;
    return;
}
if(visit[row][col])
    return;
visit[row][col]=1;
int c;
for(c=0;c<=3;c++){
    traverseMaze(row+pr[c],col+pc[c]);
    if(jue){
        ar[row][col]='.';
        return;
    }
}
}


int main(){
int a,b,str,stc;
scanf("%d",&n);
scanf("%c",&junk);
for(a=1;a<=n;a++){
    for(b=1;b<=n;b++){
        scanf("%c",&ar[a][b]);
        if(ar[a][b]=='G'){
            finr=a;
            finc=b;
        }
        if(ar[a][b]=='S'){
            str=a;
            stc=b;
        }
    }
    scanf("%c",&junk);
    }
traverseMaze(str,stc);
ar[str][stc]='S';
for(a=1;a<=n;a++){
    for(b=1;b<=n;b++){
        printf("%c",ar[a][b]);
    }
    printf("\n");
}

}
/*
12
############
#   #      #
S # # #### #
### #    # #
#    ### # #
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #G  #
############
*/

