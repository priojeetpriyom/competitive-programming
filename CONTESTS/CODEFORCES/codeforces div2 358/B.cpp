#include <bits/stdc++.h>

using namespace std;
vector<int> vec;
int main ()
{

    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
    vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    int mn=0;
    vec[0]=1;
    int fac=2;
//    for(int i=0; i<n; i++)
//    {
        for(int i=1; i<n; i++)
        {
            if(vec[i] >= fac)
            {
                vec[i] = fac;
                fac++;
//                cout<<vec[i]<<" ";
            }
        }
//        for(int i=0; i<n; i++)
//            printf("%d ",vec[i]);
//        printf("\n");
        fac=1;
        for(int i=0; i<n; i++)
        {
            if(vec[i] == fac) {
                fac++;
            }
        }

//    }
//        if(fac== n)
//                printf("%d\n",n+1);
//        else
            printf("%d\n",fac);
}


