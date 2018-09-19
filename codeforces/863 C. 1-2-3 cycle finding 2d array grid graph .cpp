#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

map<pair<ll,ll>, ll> mp;
map<pair<ll,ll>, pair<ll, ll> > mp2;


ll ab[5][5], ba[5][5];
int roundWinner(ll cur_a, ll cur_b)
{
    if(cur_a == cur_b) return 0;

    if(cur_a==1)
    {
        if(cur_b==3) return 1;
        else return 2;
    }
    else if( cur_a==2)
    {
        if(cur_b==1) return 1;
        else return 2;
    }
    else
    {
        if(cur_b==2) return 1;
        else return 2;
    }

}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll k;
    ll cur_a, cur_b;

    cin>>k>>cur_a>>cur_b;

    ll cnt=0;
//    k--;

    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++ )
        {
            cin>>ab[i][j];
        }
    }
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=3; j++ )
        {
            cin>>ba[i][j];
        }
    }
    ll ans_a=0, ans_b=0, pre_a=0, pre_b=0;

//    int f=0;

//    if(roundWinner(cur_a, cur_b))
//    {
//        if(roundWinner(cur_a, cur_b)==1)
//            f=1;
//        else f=2;
//    }

//    ll temp = cur_a;
//    cur_a = ab[cur_a] [cur_b];
//    cur_b = ba[temp] [cur_b];

    ll frequency=0;

    while(cnt<k)
    {
//        printf("cnt %lld a %lld b %lld\n",cnt,  cur_a, cur_b);
        if(mp.count(make_pair(cur_a, cur_b)))
        {
//            printf("cnt %lld found loop\n", cnt);
            frequency = cnt - mp[make_pair(cur_a, cur_b)];
            pre_a = mp2[make_pair(cur_a, cur_b)].first;
            pre_b = mp2[make_pair(cur_a, cur_b)].second;
            ans_a -= pre_a;
            ans_b -= pre_b;
            break;
        }
        ll temp_a= cur_a;

        mp[make_pair(cur_a, cur_b)]=cnt;
        mp2[make_pair(cur_a, cur_b)] = make_pair(ans_a, ans_b);

        if(roundWinner(cur_a, cur_b)) {
            if(roundWinner(cur_a, cur_b)==1) ans_a++;
            else ans_b++;
        }

        cur_a = ab[cur_a] [cur_b];
        cur_b = ba[temp_a] [cur_b];

        cnt++;


    }
//    printf("frequency %lld ans_a %lld ans_b %lld\n", frequency, ans_a, ans_b);
//    printf("cnt %lld pre_a %lld pre_b %lld\n",cnt, pre_a, pre_b);

    if(frequency)
    {
        ans_a += (ans_a * ( (k-cnt) /frequency) );
        ans_b += (ans_b * ( (k-cnt)/frequency) );
        k= (k-cnt)% frequency;
    } else k-=cnt;


    while(k--)
    {
        int temp_a= cur_a;

        if(roundWinner(cur_a, cur_b)) {
            if(roundWinner(cur_a, cur_b)==1) ans_a++;
            else ans_b++;
        }

        cur_a = ab[cur_a] [cur_b];
        cur_b = ba[temp_a] [cur_b];

    }
//    if(f==1) ans_a++;
//    else if(f==2) ans_b++;

    cout<<ans_a+pre_a<<" "<<ans_b+pre_b<<endl;






    return 0;
}

