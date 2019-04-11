#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
//    //freopen("myInput.txt",") ;;;

    int offDays=2;
    int days;
//    while(1)
    {
        scanf("%d",&days);

        if(days%7 == 0)
            printf("%d %d\n",(days/7)*offDays,(days/7)*offDays);
        else
            {
                int x;
                x= days%7;
    //printf("x%d\n",x);
                //x-=5;
                int y=0;
                if(x>5)
                    y= x-5;
                x= min(2,x);

                printf("%d %d\n",(days/7)*offDays+y,(days/7)*offDays + x);
            }
    }
           return 0;

}

