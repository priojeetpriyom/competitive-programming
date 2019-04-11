#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout<<bitset<10>(64);
    string s;
    string t="1000000";
    cin>>s;
    int flag=0;


    for(int i=0; i<s.size(); i++) {
        if(s[i] =='1') {
            int temp=0;
            for(int j=i+1; j<s.size(); j++) {
                if(s[j]=='0')
                    temp++;
            }
            if(temp>=6)
                flag=1;
            break;
        }


    }

    if(!flag ) {
        cout<<"no"<<endl;
    }else cout<<"yes"<<endl;



    return 0;
}


