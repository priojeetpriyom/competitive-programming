Pupils Redistribution
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int n, ara1[10], ara2[10];
int main()
{
    cin>>n;
    int x;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        ara1[x]++;
    }
    for(int i=0; i<n; i++)
    {
        cin>>x;
        ara2[x]++;
    }

    for(int i=1; i<=5; i++)
    {
        if((ara1[i] +ara2[i]) %2 ==1)
        {
            cout<<-1;
            return 0;
        }
    }

    int cnt1=0, cnt2=0;
    for(int i=1; i<=5; i++)
    {
        if(ara1[i]> ara2[i])
            cnt1 += (ara1[i] - ara2[i]);
        else
            cnt2 += (ara2[i] - ara1[i]);
    }

    if(cnt1 == cnt2)
        cout<< (cnt1+1)/2;
    else
        cout<<-1;

    return 0;
}
