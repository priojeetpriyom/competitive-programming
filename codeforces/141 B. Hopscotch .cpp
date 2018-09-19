#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    //while(1)
    {
        double a,x,y;
    int num, height;
    scanf("%lf %lf %lf",&a, &x, &y);
    height = ceil( y/a) -1;
    if((int)y % (int)a==0)
    {
        printf("-1\n");
        //continue;
        return 0;
    }

    //scanf("%d",&height);
    //height--;
    if(height%2==0)
    {
        num= height/2 + height +1;
    }
    else
    {
        num = height/2+ (height/2)*2 +2;
    }
//    printf("num %d\n",num);
    if(num%3==2 || num==1)
    {
        if(a/2>abs(x))
            printf("%d\n",num);
        else
            printf("-1\n");
    }
    else
    {
        if(a>abs(x) && x!=0)
            {
                if(x>0)
                    printf("%d\n",num);
                else
                    printf("%d\n",num-1);
            }
        else
            printf("-1\n");
    }

    }
    return 0;
}


