#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string s;
    cin>>s;
    int len = s.size();
//    bool palin= false;
//    for(int i=0; i<len; i++) {
//        string temp = s;
//        cout<<temp<<endl;
//        int len_temp = temp.size();
        int cnt=0;

        for(int j =0; j<(len+1)/2; j++) {
            if(s[j] != s[len-j-1]) {
                cnt++;
            }
        }
//        if(x) palin = true;
//    }
//    cout<<cnt<<endl;
    if((cnt<=1&& len%2!=0) || (cnt==1 && len%2==0)) cout<<"YES";
    else cout<<"NO";

    return 0;
}


