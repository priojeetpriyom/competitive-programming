#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//#include <stdio.h>
//#include <string.h>
//#define ll long long


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int b, a;
    cin>>b>>a;

     a<<=1;
     b  = (a/b) + (a%b!=0);
     cout<<b<<endl;


    return 0;
}

