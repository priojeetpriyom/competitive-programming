#include <bits/stdc++.h>
using namespace std;

long long getPow2(long long num) {
    long long n=1;

    for(int i=0; i< num; i++)
        n = n<<1;
    return n;
}

int main()

{
    long long n,k;
    cin>>n>>k;
    long long x = k;
//    if(n==1)
//        cout<<1;     HAVE TO HANDLE EDGE
    long long cur=1, pw =2;
//    for(long long i=1; ; )
//    {
//        pw = pw<<1;
//        i = pw-1;
//        cur++;
//        if(i>=k)
//            break;
//        k -= i;
//    }
    k=x;
    long long num =n;
    cur = getPow2(n-1);
    if(k>cur)
        k-=cur;

    while(cur != k) {
        if(cur < k) {
                k -= cur;
//            cur = cur + getPow2(num-1);
//            num++;
        } else {
            num--;
            cur = cur - getPow2(num-1);
        }
    }
    cout<<num;
    return 0;
}

