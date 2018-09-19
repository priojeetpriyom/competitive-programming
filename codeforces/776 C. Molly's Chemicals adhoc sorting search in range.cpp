#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll pows[100], n, k, cum[100100];


ll getLog(ll num , ll base) {
    int ans=0;
    while(num>0) {
        num/=k;
        ans++;
    }
    return ans;
}

int main()
{
//        freopen("out.txt", "w", stdout);

    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        cin>>cum[i];
//        mp[cum[i]] =1;
    }
    ll lim = getLog(1e15, abs(k))+1;



    int len_pow =0;
//    pows[0]=0;
    pows[len_pow++] = 1;
    if(abs(k)!=1)
    {
        ll pw =k;
        while(abs(pw)<= 1e15)
        {
            pows[len_pow++] = pw;
            pw = pw*k;
        }
    }
    if(k== -1)
        pows[len_pow++] = -1;
    ll cnt=0;

//    for(int i=1; i<=n; i++) {
//        for(int j=1; j<len_pow; j++)
//            if(cum[i] == pows[j])
//                cnt++;
//    }

//    printf("powers\n");
//
//    for(int i=0; i<len_pow; i++)
//        printf("%I64d ", pows[i]);
//    printf("\n");
//
    for(int i=1; i<=n; i++)
    {
        cum[i]+=cum[i-1];
//        mp[cum[i]]++;
    }

    for(int j=0; j<len_pow; j++)
    {
        map<ll, int> mp;
        mp[0] = 1;
        for(int i=1; i<=n; i++)
        {
            if(mp.find(cum[i]-pows[j]) != mp.end())
            {
                cnt+= mp[cum[i] - pows[j]];
//                    mp[cum[i] +pows[j]] = -1;
//                    printf("i %d sum %I64d pow %I64d\n", i, cum[i]+pows[j], pows[j]);
            }
            mp[cum[i]] ++;
        }
    }

    cout<<cnt;

    return 0;
}



