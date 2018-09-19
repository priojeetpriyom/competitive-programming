#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


string s;

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);  cin.tie(0);


    int t;

    cin>>t;

    while(t--) {

        cin>>s;

        char prev= -1;
        int cnt=1;
        int mx=1;
        int len = s.size();
        for(int i=0; i<len; i++) {
            if(s[i]=='=') continue;
            if(s[i] == prev)
                cnt++;
            else if(s[i]!= '=')
                cnt=1;

            mx = max(mx, cnt+1);
            if(s[i]!= '=')
            prev = s[i];


        }

        cout<<mx<<endl;


    }



    return 0;

}

