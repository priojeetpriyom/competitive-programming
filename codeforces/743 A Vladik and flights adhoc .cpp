#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, a, b;
    cin>>n>>a>>b;
    char str[100001];
    cin>>str;
    if(str[a-1] == str[b-1])
        cout<<"0";
    else
        cout<<"1";

    return 0;
}


