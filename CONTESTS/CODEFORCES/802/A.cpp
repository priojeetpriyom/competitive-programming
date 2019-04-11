#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int ara[100], seq[100];


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<int> sset;

    int n, k;

    cin>>n>>k;

    int x;

    for(int i=0; i<n; i++)
    {
        cin>>x;
        seq[i]=x;
        ara[x]++;
    }
    int cnt =0;
    for(int i=0; i<n; i++)
    {
        if(sset.find(seq[i]) == sset.end())
        {
            if(sset.size() == k)
            {
                int mn = 1e9, mn_ind;
                for(set<int> :: iterator it = sset.begin(); it!= sset.end(); it++)
                {
                    {
                        if(ara[*it] < mn)
                        {
                            mn = ara[*it];
                            mn_ind = (*it);
                        }
                    }

                }
                sset.erase(sset.find(mn_ind));
            }
            sset.insert(seq[i]);
            cnt++;
        }
        ara[ seq[i]]--;
    }

    cout<<cnt<<endl;

    return 0;
}


