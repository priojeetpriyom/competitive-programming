#include <bits/stdc++.h>
using namespace std;

int sum[100010];
vector<long long> vec;

long long getDigSum(long long x) {
    int sum=0;
    while(x>0) {
        sum+= x%10;
        x/=10;
    }
    return sum;
}

long long getPow(long long x, long long n) {
    long long pw=1;
    for(int i=0; i<n; i++) {
        pw*=x;
        if(pw>1000100000)
            return pw;
    }
    return pw;
}

int main()
{
//    freopen("myOut.txt", "w", stdout);

    long long x,a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    for(long long i =1; i<=81; i++) {
        x = b* getPow(i,a) +c;
        long long y = b* getPow(getDigSum(x),a) +c;
        if(x== y && x>0&& x<1000000000)
            vec.push_back(x);
    }

    for(int i=0; i<vec.size(); i++)
    {
        bool uni = true;
        for(int j = i-1; j>=0; j--) {
            if(vec[j] == vec[i])
                {
                    uni = false;
                    break;
                }
        }
        if(uni)
        {
            cnt++;
//            cout<<vec[i]<<" ";
        }
    }
    cout<<cnt<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        bool uni = true;
        for(int j = i-1; j>=0; j--) {
            if(vec[j] == vec[i])
                {
                    uni = false;
                    break;
                }
        }
        if(uni)
        {
//            cnt++;
            cout<<vec[i]<<" ";
        }
    }
    return 0;
}



