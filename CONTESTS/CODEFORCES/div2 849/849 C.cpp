#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



    string ans;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k;

    cin>>k;
    if(k==0) {
        cout<<"a"<<endl;
        return 0;
    }

    for(int i=0; i<26; i++)
    {
        string temp;
        int sum=0, val=0;
        if(k)
            while(k-val >=0)
            {
                k-=val;
                val++;
                temp =(char) (97+i);
                ans+= temp;
            }
    }
//    cout<<ans.size()<<endl;
    cout<<ans<<endl;



    return 0;
}


