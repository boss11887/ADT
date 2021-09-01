#include <stdio.h>
//last2 / last2/4 mod7
int monthcode[2][13]={{0,0,3,3,6,1,4,6,2,5,0,3,5},{0,6,2,3,6,1,4,6,2,5,0,3,5}};
int centurycode[]={6,4,2,0};
int dayofmonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[] =
        {" ",
         "January",
         "February",
         "March",
         "April",
         "May",
         "June",
         "July",
         "August",
         "September",
         "October",
         "November",
         "December"};

int leapchk(int year){
    int ans;
    if (year % 400 == 0) {
      ans=1;
   }
   else if (year % 100 == 0) {
      ans=0;
   }
   else if (year % 4 == 0) {
      ans=1;
   }
   else {
        ans=0;
   }
   return ans;
}

int main(){
    int month,year,start,cnt=0,j;
    printf("Enter year: ");
    scanf("%d",&year);
    printf("Enter month: ");
    scanf("%d",&month);
    int ym100=year%100;
    int cc=leapchk(year);
    int cal = (1 + monthcode[cc][month] + centurycode[(year/100)%4] + ym100 +ym100/4)%7;
    printf("====================\n");
    printf("%s %d\n",months[month],year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    int thismonth=dayofmonth[month];
    if(month==2)
        thismonth+=cc;

    while(cnt < thismonth){
        if(j==cal || cnt!=0){
        cnt++;
        printf("%3ld ", cnt);
        }else{
            printf("    ");
        }
        j++;
        if (j==7)
        {
            j=0;
            printf("\n");
        }
    }
    return 0;}
