#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long lll;
#define MX 500100

int main()
{

    int k[10];

    for(int i=0; i<3; i++)
        cin>>k[i];
    int one=0, two=0, three=0;
    for(int i=0; i<3; i++) {
        if(k[i]==1) one++;
        else if(k[i] == 2) two++;
        else if(k[i]==3) three++;
    }
    sort(k, k+3);
    if(one>0 || two>1 || three>2 || (k[0]==2 && k[1]==4 && k[2]==4))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    return 0;
}
