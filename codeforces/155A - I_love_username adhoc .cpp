#include <bits/stdc++.h>
using namespace std;



int main()
{
    int high, low= -1;
    int n, cnt=0, x;
    cin>>n>>high;
    for(int i=1; i<n; i++)
    {
        cin>>x;
        if(low == -1)
        {
            low = x;
            if(low != high)
                cnt++;
            if(low > high)
                swap(low, high);
//            printf(" cnt %d\n", cnt);
        }
        else if(x>high)
        {
            cnt++;
            high = x;
        }
        else if(x<low)
        {
            cnt++;
            low = x;

        }
//        cout<<x<<"=> "<<high<<" "<<low<<endl;
    }
    cout<<cnt;
    return 0;
}

