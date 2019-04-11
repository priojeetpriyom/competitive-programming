#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int ans[5555];
    string s;


bool is_palindrom(int i, int j) {

        while(i<j) {
            if(s[i]!= s[j]) return false;
            i++;j--;
        }

    return true;

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin>>s;

    int len = s.size();

    for(int i=0; i<len; i++) {
        for(int j = i; j<len; j++) {
            if(is_palindrom(i,j)) {
                cout<<s.substr(i, j-i+1)<<endl;
                ans[1]++;
                if( ((j-i+1)>>1)>=1 )
                    ans[ ((j-i+1)>>1)+1 ]++;
            }
        }
    }

    for(int i=1; i<=len; i++) cout<<ans[i]<<" "; cout<<endl;




    return 0;
}


