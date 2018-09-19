#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int x1,x2,x3,x4,y1,y2,y3,y4;
    int n,i;
    scanf("%d",&n);
    i=n;
    {
        if(i>0)
            scanf("%d %d",&x1, &y1);
        i--;
        if(i>0)
            scanf("%d %d",&x2, &y2);
        i--;
        if(i>0)
            scanf("%d %d",&x3, &y3);
        i--;
        if(i>0)
            scanf("%d %d",&x4, &y4);
        i--;
    }

    if(n==1)
        printf("-1\n");
    else if(n==2)
    {
        if(x1!=x2 && y1!=y2)
        {
            printf("%d\n",abs((x2-x1)*(y2-y1)));
        }
        else
            printf("-1\n");
    }
    else if(n==3)
    {
        if(x1!=x2 && y1!=y2)
        {
            printf("%d\n",abs((x2-x1)*(y2-y1)));
        }
        else if (x1!=x3 && y1!=y3)
            printf("%d\n",abs((x3-x1)*(y3-y1)));
        else
        {
            if(x1==x2)
                x4=x3;
            else if(x1==x3)
                x4=x2;
            else if(x2==x3)
                x4=x1;

            if(y1==y2)
                y4=y3;
            else if(y1==y3)
                y4=y2;
            else if(y2==y3)
                y4=y1;

            printf("%d\n",abs((x4-x1)*(y4-y1)));
        }

    }
    else
    {
        if(x1!=x2 && y1!=y2)
        {
            printf("%d\n",abs((x2-x1)*(y2-y1)));
        }
        else if (x1!=x3 && y1!=y3)
            printf("%d\n",abs((x3-x1)*(y3-y1)));
        else
            printf("%d\n",abs((x4-x1)*(y4-y1)));

    }
    return 0;
}


