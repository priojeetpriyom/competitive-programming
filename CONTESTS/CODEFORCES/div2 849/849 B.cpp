#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


map<pair<int, int>, int > mp;
vector<pair<int,int> > vec;
map< pair<int, int> , int>::iterator it;
pair<int, int> pre(int len) {

    for(int i=1; i<len; i++) {
        int y = vec[i].second - vec[0].second;
        int x = vec[i].first - vec[0].first;
        if(x<0 && y<0) {
            x = abs(x);
            y = abs(y);
        } else if(y<0) {
            y = abs(y);
             x = (-1) * x;
        }
        if(__gcd(abs(x), abs(y))>1) {
            int temp = __gcd(abs(x), abs(y));
            x/=temp;
            y/=temp;
        }
        mp[{x,y}]++;
    }
    int mx=0;
    pair<int, int> ans = {0,0};
    for(it= mp.begin(); it!= mp.end(); it++ )
     {
         printf("{%d, %d}-> %d \n",it->first.first, it->first.second, it->second );
         if(it->second>= mx ) {
            mx = it->second;
            ans = it->first;
         }
     }

     return ans;
 }

 pair<int, int>get_tangent(int pos1, int pos2) {


        int y = vec[pos1].second - vec[pos2].second;
        int x = vec[pos1].first - vec[pos2].first;

        if(x<0 && y<0) {
            x = abs(x);
            y = abs(y);
        } else if(y<0) {
            y = abs(y);
             x = (-1) * x;
        }

        if(__gcd(abs(x), abs(y))>1) {
            int temp = __gcd(abs(x), abs(y));
            x/=temp;
            y/=temp;
        }

        return {x,y};


 }


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int y;

    for(int i=1; i<=n; i++) {
        cin>>y;
        vec.push_back({i,y});


    }

    pair<int, int> tangent = pre(n), tangent2;
    printf("tangent x %d y %d\n", tangent.first, tangent.second);
    int cnt=1;
    for(int i=1; i<n; i++) {
        if(get_tangent(0, i) == tangent) {
            vec[i] = {0,0};
            cnt++;
        }
    }
    printf("cnt %d\n", cnt);

    if(cnt==n) {
        cout<<"No"<<endl;
        return 0;
    }
    int cnt2=0;
    int f=0;
    int one;
    for(int i=1; i<n; i++) {
        if(vec[i] != make_pair(0,0)) {
            f++;
            if(f<2) {
//                if(f==1) {
                    one = i;
//                } else {

//                }
                cnt2++;
                continue;
            } else {
                if(f==2) {
                    tangent2 = get_tangent(one, i);
                    if(tangent2!= tangent) {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
                if(get_tangent(one, i) == tangent) {
                    cnt2++;
                }
            }
        }
    }

    if(cnt2+cnt == n) {
        cout<<"Yes"<<endl;
    }else cout<<"No"<<endl;



    return 0;
}


