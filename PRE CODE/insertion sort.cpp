#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int main()
{
//    freopen("myOut.txt", "w", stdout);

    int num[10];
    for(int i=1; i<6; i++)
        cin>>num[i];
    int n=5;

    for ( int i = 2; i <= n ; i ++)
    {
        int x = num[i];
        int j;
        for(j = i-1; j>0; j--)
        {
            if ( num [ j ] < x )
            {
                break;
            }
            num[j+1] = num[j];

        }
        num[j+1] = x;
    }

    for ( int i = 1; i <= n ; i ++)
        cout<<num[i]<<" ";

return 0;
}
