#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a,b;
    cin>>a>>b;
    if(a==0 && b==0)
        printf("NO\n");
    else if(abs(a-b) <=1)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;

}

