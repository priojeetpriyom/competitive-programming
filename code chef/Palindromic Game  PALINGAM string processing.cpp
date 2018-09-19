#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



//int calc_mx(string one, string two)
//{
//
//    int chars[300];
//    memset(chars, 0, sizeof chars);
//    int len = one.size();
//    for(int i=0; i<len; i++)
//        chars[one[i] ]++;
////    for(int i=0; i<len; i++)
////        if(chars[two[i] ]) chars[two[i]]=0;
//    int mx=0;
//    for(int i=0; i<len; i++)
//        mx = max(mx, chars[one[i] ]);
//
//    return mx;
//
//
//
//}
int calc(string one, string two)
{

    int chars[300];
    memset(chars, 0, sizeof chars);
    int len = one.size();
    for(int i=0; i<len; i++)
        chars[one[i] ]++;
    for(int i=0; i<len; i++)
        if(chars[two[i] ]) chars[two[i]]=0;
    int mx=0;
    for(int i=0; i<len; i++)
        mx = max(mx, chars[one[i] ]);

    return mx;



}


int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;

    cin>>t;

    while(t--)
    {

        string a, b;
        cin>>a>>b;

        int uncommon_a = calc(a,b), uncommon_b = calc(b,a);

//        cout<<uncommon_a<<" "<<uncommon_b<<endl;
        if( (uncommon_a && (!uncommon_b)) || uncommon_a>1 ) cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }


    return 0;
}


