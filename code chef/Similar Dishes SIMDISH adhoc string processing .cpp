#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n;
    cin>>n;

    while(n--) {
        map<string, bool> mp;
        string temp;
        int cnt=0;
        for(int i=0; i<4; i++)
        {
            cin>>temp;
            mp[temp]=1;
        }

        for(int i=0; i<4; i++)
        {
            cin>>temp;
            if(mp[temp])
                cnt++;
        }
        if(cnt>1)
            printf("similar\n");
        else
            printf("dissimilar\n");

    }

    return 0;
}




