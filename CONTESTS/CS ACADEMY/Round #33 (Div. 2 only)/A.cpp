#include <bits/stdc++.h>

using namespace std;
typedef long long ll;






int n, ara[111] [111], ans[111];


int calc(int a, int b)
{

    int mx=0, mn=0;
    map<int, int>mp;
    map<int, int>::iterator it;
    for(int i=0; i<n; i++)
    {
        if(!mp[ara[a] [i] ])
            mp[ ara[a][i] ]=1;


    }
    for(int i=0; i<n; i++)
    {
        if(mp[ara[b][i] ] ==1)
         mp[ ara[b][i] ]=2;
    }
    for(it = mp.begin(); it!= mp.end(); it++)
    {
        if(it->second>1)
        {
            mn = it->first;
            break;
        }
    }
    for(it = (--mp.end()); ; it--)
    {
        if(it->second>1)
        {
            mx = it->first;
            break;
        }
        if(it == mp.begin()) break;
    }
    int cnt1=0, cnt2=0;

    for(int i=0; i<n; i++)
    {
        if(ara[a][i]<mn || ara[a][i] > mx) cnt1++;
    }
    for(int i=0; i<n; i++)
    {
        if(ara[b][i]<mn || ara[b][i] > mx) cnt2++;
    }

    if(cnt1> cnt2) return 1;
    if(cnt2>cnt1) return -1;

    return 0;




}



bool cmp (pair<int, int> a, pair<int, int> b)
{
    if(a.first!= b.first)
        return a.first > b.first;


        return (a.second < b.second);

//    return false;

}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ara[i][j];
        }
    }


//    for(int i=0; i<n; i++)
//    {
//        sort(ara[i], ara[i]+n);
//    }



    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            x= calc(i, j);
            if(x>0) ans[i]+=2;
            else if(!x)
            {
                ans[i]++;
                ans[j]++;
            }
            else ans[j]+=2;
        }
    }

    vector<pair<int, int> > temp;

    for(int i=0; i<n; i++) temp.push_back(make_pair(ans[i], i) );

    sort(temp.begin(), temp.end(), cmp);


    for(int i = 0; i<n; i++) cout<<temp[i].second+1<<endl;



}

