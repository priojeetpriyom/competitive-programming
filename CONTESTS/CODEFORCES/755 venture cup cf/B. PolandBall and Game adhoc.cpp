#include <bits/stdc++.h>
using namespace std;


int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    map<string, int> mp;

    int n,m;
    cin>>n>>m;

    int cnt1, cnt2, cnt=0;
    string s;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        cin>>s;
        mp[s] =1;
    }
    cnt1 = n;cnt2 = m;

    for(int i=0; i<m; i++) {
        cin>>s;
        if(mp.find(s) != mp.end())
            cnt++;
    }
//    printf("cnt %d\n", cnt);
    cnt1= cnt1 - cnt;
    cnt2-=cnt;
    if(cnt %2 ==1)
    {
        cnt1++;
    }

    if(cnt1>cnt2)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}




