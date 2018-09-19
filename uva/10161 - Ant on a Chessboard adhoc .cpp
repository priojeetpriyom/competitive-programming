#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,root,square,x,y;
    while(scanf("%d",&n)==1 && n!=0)
    {
        root= sqrt(n);
        square=root*root;
        //cout<<square<<endl;
        if(root%2==0)
        {
            //printf("n %d square %d\n",n,square);
            root++;
            if(square==n)
            {
                //printf("1 %d\n",root);
                x=root-1,y=1;

            }
            else if(n-square<=root)
            {


                x=root;
                y=n-square;
            }
            else
            {
                n-=square;
                n-=root;
                y=root;
                x= (root-n);
            }
        }
        else
        {
            root++;
            if(square==n)
            {
                x=1,y=root-1;
            }
            else if(n-square <= root)
            {
                y=root;
                x=n-square;
            }
            else
            {
                n-=square;
                n-=root;
                x=root;
                y=root-n;
            }
        }
        printf("%d %d\n",x,y);
    }

    return 0;
}

