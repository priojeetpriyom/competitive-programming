#include <stdio.h>
int main()
{
    int i,j,s,a[]={1,2,3,4,5,6,7,8,9},b[10];
    for(i=0,j=9;i<5&&j>=5;i++,j--){
            s=a[i];
            a[j]=s;
            //printf("%d",a[j]);
               }
    //r(j=0;j<9;j++){
       //rintf("%d",b[j]);}
       for(i=0;i<9;i++)
       printf("%d",a[i]);
    return 0;
}
