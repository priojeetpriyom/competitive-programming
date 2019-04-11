#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long b,d,s;
    scanf("%I64d %I64d %I64d", &b, &d, &s);
    if(b<s)
        swap(b,s);
    if(b<d)
        swap(b,d);
//    long long mx = max(max(b,d), max(b,s));
//    long long mn = min (min(b,d), min(b,s) );
//    printf("%I64d\n", max((long long)0, (mx-mn-1)));
    long long x = max((long long)0, (b-d-1));
    long long y = max((long long)0, (b-s-1));

    printf("%I64d\n",  x+y );
    return 0;
}

