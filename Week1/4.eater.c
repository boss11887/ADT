#include<stdio.h>

int main(){
  int q,w,e;  
  char a,b;  
  scanf("%d %d %d %c %c",&q,&w,&e,&a,&b);
  int ans=q;
  if (a == 'Y' || a == 'y') 
    ans+=w;
  if (b == 'Y' || b == 'y'){
    float temp = (float)ans/e;
    if (temp - (int)(ans/e) != 0.0) 
        printf("%d",ans/e+1);
    else 
        printf("%d",ans/e);
  }else{ 
      printf("%d",ans);
  }
  return 0;
}