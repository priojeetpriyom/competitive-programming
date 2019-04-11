#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, one_full_left, two_full_left;

    cin>>n>>one_full_left>>two_full_left;
    int two_half_left=0;


    int ans=0;

    int x;

    while(n--) {

        cin>>x;
        if(x==1) {
            if(one_full_left) {
                one_full_left--;
            } else if(two_full_left)
            {
                two_full_left--;
                two_half_left++;
            }
            else if(two_half_left) {
                two_half_left--;
            } else ans++;

        } else {
            if(two_full_left)
                two_full_left--;
            else ans+=2;

        }

    }

    cout<<ans<<endl;


    return 0;
}


