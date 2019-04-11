#include <bits/stdc++.h>

using namespace std;
//typedef long long ll;
//typedef unsigned long long ull;
//#define MX 100100
vector<string> vec;
bool is_substring(string a, string b)
{
    if(a.length()> b.length())
        return false;
    for(int i=0; i< b.length()-a.length()+1; i++)
    {
        if(a == b.substr(i, a.length()))
            return true;
    }
    return false;
}
struct node {
    int cnt=0, pos;
} ara[111];


bool cmp(node a, node b)
{
    return a.cnt<b.cnt;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        vec.push_back(s);
    }
    if(n==1)
    {
        cout<<"YES"<<endl<<vec[0]<<endl;
        return 0;
    }

//    sort(vec.begin(), vec.end(), cmp);

    for(int i=0; i< n; i++)
    {
        ara[i].pos = i;
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(is_substring(vec[j], vec[i]))
                {
                    ara[i].cnt++;
                }
            }
        }
//        cout<<"i "<<i<<" str "<<vec[i]<< " cnt "<<ara[i].cnt<<endl;
    }

    sort(ara, ara+n, cmp);


    for(int i=0; i<n; i++)
    {
        if(ara[i].cnt<i) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<vec[ara[i].pos ]<<endl;
    }


    return 0;
}


