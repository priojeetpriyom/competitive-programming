#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

vector<int> vec;


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, u;
    cin>>n>>u;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }

    double mx=-1;
    vector<int>:: iterator it;
    for(int i=0; i<n; i++)
    {
        if(u>=vec[i])
            continue;
        it = lower_bound(vec.begin(), vec.end(), vec[i]-u);
        if(*it> vec[i]-u) {
            if(it == vec.begin())
            continue;
            else
                it--;
            double temp = vec[i] - *(++it);
            it--;
            temp = temp / (vec[i] - *it);
            mx = max(mx, temp);
        }
    }

    cout<<mx<<endl;


    return 0;
}


