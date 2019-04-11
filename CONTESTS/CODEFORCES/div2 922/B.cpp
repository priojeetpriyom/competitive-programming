

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

//map<tuple<int, int, int> > mp;
int vis[2511] [2511];
//map<pair<int, int>, map<int, int>> mp;
//map<int, map<int, map<int, int> > >mp;
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n;
    scanf("%d", &n);
//    n=10;
    ll ans=0;
    pair <int, int> p;
    for(int a=1; a<=n; a++) {
        for(int b = a+1; b<=n; b++) {
//                int mx = min(n, a+b);
                int xorr = a^b;
                int mn1, mn2, mn3;
//            for(int c = 1; c <mx; c++) {
                if( xorr <=n && (xorr<a+b && a+xorr>b && b+xorr>a))
                {
                    if(a<=b && a<=xorr)
                    {
                        mn1 = a;
                        if(b<=xorr)
                            mn2=b, mn3 = xorr;
                        else
                            mn2=xorr, mn3 = b;

                    } else if(b<=a && b<=xorr) {
                        mn1 = b;
                        if(a<=xorr)
                            mn2=a, mn3 = xorr;
                        else
                            mn2=xorr, mn3 = a;
                    } else {
                        mn1 = xorr;
                        if(a<=b)
                            mn2=a, mn3 = b;
                        else
                            mn2=b, mn3 = a;
                    }
//                    p = {mn1, mn2};
//                    mp[mn1][mn2] [mn3];
//                    mp.find(1).find(2);
                    if(vis[mn1][mn2]==1)
                        continue;
//                    if(mp.find(mn1)!=mp.end()) {
//                        map<int, map<int, int> > mp2 = mp[mn1];
//                        if(mp2.find(mn2)!= mp2.end()) {
//                            map<int, int> mp3 = mp2[mn2];
//                            if(mp3.find(mn3) != mp3.end())
//                                continue;
//                            else
//                                mp3[mn3]=1;
//                            mp2[mn2] = mp3;
//                            mp[mn1] = mp2;
//                        }
//                        printf("aise\n");
//                    }
                    vis[mn1] [ mn2 ]=1;
//                    cout<<a<<" "<<b<<" "<<xorr<<endl;
//                    cout<<mn1<<" "<<mn2<<" "<<mn3<<endl;
                    ans++;
                }
            }
        }
//    }

    printf("%I64d\n", ans);


    return 0;
}



