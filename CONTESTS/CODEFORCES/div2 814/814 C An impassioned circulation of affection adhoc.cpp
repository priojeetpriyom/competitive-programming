#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
char str[1505];

int ans;
map<int, int> mp[30];


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

//memset(dp, -1, sizeof dp);
    int  q;
    scanf("%d \n%s %d", &n, str, &q);
    int cnt=1;
    char c= str[0] - 'a';
    for(int i=0; i<n; i++) {
        str[i]-= 'a';
    }
//    for(int i=0; i<26; i++) {
////        sset[i].insert(-1);
//        sset[i].insert(1e6);
//    };


    for(int i=0; i<26; i++) {

            map<int, int> &mpp = mp[i];
        int l,r;
        for(l=1; l<=n; l++) {
        int cnt=0;
            for(r=0; r<l; r++) cnt += (str[r] == i);
//            sset[i].insert(l - cnt);
            mpp[l - cnt];
            mpp[l-cnt] = max(mpp[l-cnt], l);
            for(r = l; r<n; r++) {
                cnt+= ( (str[r] == i) - (str[r-l] == i));
//                sset[i].insert(l-cnt);
                mpp[l-cnt];
                mpp[l-cnt] = max(mpp[l-cnt], l);
//                if(i+'a' == 'm') {
//                    printf("l %d r %d cnt %d l-cnt %d mp %d\n", l, r, cnt, l-cnt, mpp[l-cnt]);
//                }
            }

        }

    }
//    mp.lower_bound()

    int m;
//    char c;
//    printf("n %d\n", n);

    while(q--) {
        scanf("%d \n%c", &m, &c);
        c-= 'a';
        ans=0;
//    printf("n %d\n", n);
        map<int, int> &mpp = mp[c];

        map<int, int> :: iterator it = mpp.lower_bound(m);
//        printf("lower_bound m %d range %d\n", it->first, it->second);

        if(it == mpp.begin() && it->first >m ) ans=0;
        else if(it == mpp.end()) ans = n;
        else if(it->first > m) it--;
        else
            ans = it->second;




            printf("%d\n", ans);
        }
//    printf("n %d\n", n); //qadwsasd




    return 0;
}


