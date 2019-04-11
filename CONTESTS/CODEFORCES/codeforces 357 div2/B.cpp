#include <bits/stdc++.h>
using namespace std;

int ara[4] = {1234,123456,1234567};
    bool yes=false;
void findCombination (int n) {
    if(n==0)
        {
            yes=true;
            return;
        }
    if(n<ara[0])
        return ;

    for(int i=0; i<2; i++) {
        if(yes)
        return;

        findCombination(n-ara[i]);
//        if(n== ara[0] || n== ara[1] || n== ara[2]);
        //printf("%d\n",n);
    }
}
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int car=123456,house=1234567,computer=1234,n;
    int x,y,z;

    scanf("%d",&n);


    //111
//    x=n%house;
//    y = x% car;
//    y = y% computer;
//    if(y==0)
//       yes=true;
//
//    y = x% computer;
//    y = y%car ;
//    if(y==0)
//       yes=true;
//
//    //222222
//    x=n% car;
//    y = x% house;
//    y = y% computer;
//    if(y==0)
//       yes=true;
//
//    y = x% computer ;
//    y = y% house;
//    if(y==0)
//       yes=true;
//
//
//    //3333333333
//
//    x=n%computer ;
//    y = x% house;
//    y = y% car;
//    if(y==0)
//       yes=true;
//
//    y = x%  car;
//    y = y% house;
//    if(y==0)
//       yes=true;


    while(n>0){
        if(n%ara[2]==0)
            {
                yes=true;
                break;
            }
        int x=n;
        while(x>0)
        {
            if(x%ara[1]==0)
            {
                yes=true;
                break;
            }
            if(x%ara[0] ==0)
            {
                yes=true;
                break;
            }
            x-=ara[1];
        }
        if(yes)
            break;
        n-= ara[2];
    }

    if(yes)
        printf("YES\n");
   else
        printf("NO\n");
    return 0;
}
