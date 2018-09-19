#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100
#define double long double
#define mod1 1000000007
#define mod2 1000000009

int vec[1111], vec2[1111];

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x, temp;
    cin>>n>>k>>x;

    for(int i=0; i<n; i++)
        cin>>temp, vec[temp]++;

//    for(auto v: vec)
//        cout<<v<<" ";
//    cout<<endl;
    int j=0;
    while(++j<=k) {
        int sum=0;
//        for(int i=0; i<1024; i++)
//            vec2[i]=0;

        for(int i=0; i<1024; i++) {

            if(sum&1) {
                vec2[i^x] += (vec[i]/2);
                vec2[i]+= ceil((double)vec[i]/2);
            } else {
                vec2[i^x] += ceil((double)vec[i]/2);
                vec2[i]+= ((double)vec[i]/2);
            }
            sum+= vec[i];
//            cout<<"i "<<i<<" sum "<<sum <<" vec2i "<<vec2[i]<<endl;
        }
//        for(auto v: vec2)
//            cout<<v<<" ";
//        cout<<endl;
        for(int i=0; i<1024; i++){
            vec[i]= vec2[i];
            vec2[i]=0;
        }

    }

    int mn=1e9, mx=0;

    for(int i=0; i<1024; i++)
    {
        if(!vec[i])
            continue;
        mn = min(mn, i);
        mx = max(mx, i);
    }

    cout<<mx<<" "<<mn<<endl;

//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
