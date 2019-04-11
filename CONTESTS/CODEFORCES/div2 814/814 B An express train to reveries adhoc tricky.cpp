#include <bits/stdc++.h>

using namespace std;
typedef long long ll;




int ara1[1111], ara2[1111], ans[1111];


    int n;

bool valid() {

    int diff=0;


    for(int i=1; i<=n; i++) {
        if(ans[i]!= ara1[i]) diff++;
    }
    if(diff!= 1 ) return false;
    diff=0;
    for(int i=1; i<=n; i++) if(ans[i] != ara2[i]) diff++;

    return (diff==1);



}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    cin>>n;

    int diff=0;


    for(int i=1; i<=n; i++) cin>>ara1[i];
    for(int i=1; i<=n; i++) cin>>ara2[i];


//    for(int i=1; i<=n; i++) {
//        if(ara1[i] != ara2[i]) diff++;
//    }

    map<int, int> mp;

//    if(diff==2) {
    int f=0;

    for(int i=1; i<=n; i++)
    {
        if(ara1[i] == ara2[i] && !mp[ara1[i]])
        {
            mp[ara1[i]]=1;
            ans[i] = ara1[i];
        }
//            else if(!mp[ ara1[i] ]) {
//                mp[ara1[i]  ] =1;
//                ans[i] = ara1[i];
//            } else if(!mp[ara2[i]  ]) {
//                mp[ ara2[i] ] =1;
//                ans[i] = ara2[i];
//            }
    }



    vector<int> vec;

    for(int i = 1; i<=n; i++)
    {
        if(!ans[i])
        {

            vec.push_back(i);

        }
    }
    vector<int> pos;

    for(int i=0; i<vec.size(); i++) {

        for(int j=1; j<=n; j++) {
            if(!mp[j])
            {
                pos.push_back(j);
                mp[j]=1;
            }
        }

    }

//    for(int i=1; i<=n; i++)
//        printf("%d ", ans[i]);printf("\n");

//    for(int i=0; i<pos.size(); i++) printf("%d ", pos[i]); printf("\n");


    f=1;

    if(pos.size()==2) {
        ans[ vec[0] ] = pos[0];
        ans[vec[1] ] = pos[1];
        if(!valid()) {
            swap(ans[vec[0]], ans[vec[1] ]);
        }
    } else if(pos.size())
         ans[vec[0]] = pos[0];


    for(int i=1; i<=n; i++)
        printf("%d ", ans[i]);


    printf("\n");
//    }



    return 0;
}


