#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1e9+7;

int type_a =1, type_b=2;

    string s;
    vector<pair<int, ll> > vec;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    cin>>s;
    int len = s.size();
    int vec_size=0;
//    printf("oka\n");
    for(int i=0; i<len; i++) {
        int type = (s[i]=='a') ? type_a : type_b;
        if(vec.size()>0 && vec[vec_size-1].first == type) {
            vec[vec_size-1].second++;
        } else {
            vec.push_back(make_pair(type, 1LL));
            vec_size++;
        }
    }

//    for(int i=0; i<vec.size(); i++) {
//        printf("i %d type %c count %I64d\n",i,vec[i].first+'A'-1, vec[i].second);
//    }


    ll ans=0;
    ll b_count=0;
    int i=vec.size()-1;
//    for(int j = vec.size()-1; j>=0; j--) {
//        if(vec[j].first != type_a){
//            b_count= vec[j].second;
//
//            for(j ; j>=0; j--) {
//                if(vec[j].first == type_a)
//                {
//                    i=0;
//                    i =j;
//                    break;
//                }
//            }
//            break;
//        }
//    }
    for( ; i>=0; i--) {
        if(vec[i].first == type_a) {
            int x = vec[i].second;
//                printf("i %d b_count %I64d x %d\n",i,b_count, x);
            while(x--) {
                ans+= b_count;
                b_count = (b_count<<1);
                if(ans>=mod) ans = ans%mod;
                if(b_count>=mod) b_count%=mod;
            }
        } else {
            b_count += vec[i].second;
//            printf("i %d b_count %I64d\n",i,b_count);
            if(b_count>=mod) b_count%=mod;
        }
     }

     cout<<ans<<endl;




    return 0;
}


