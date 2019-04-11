#include<bits/stdc++.h>

using namespace std;
typedef long long ll;




int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, pre ="heidi`";
    int len_s, len_pre = 5;
    cin>>s;

    len_s = s.size();

    int pos=0;

    for(int i=0; i<len_s; i++) {
        if(tolower(s[i]) == pre[pos]) pos++;
    }


    cout<<(pos == len_pre ? "YES":"NO" )<<endl;




    return 0;

}
