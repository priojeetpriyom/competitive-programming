///calculate prefix and suffix sum. then for every i sum for every i-k,i(prefix[i]) and max of suffix i+1,n (sufMX[i+1]).
///store the best one.
///complexity: O(N)


#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 200100
ll ara[MX], pre[MX], suf[MX], preMX[MX], sufMX[MX], prePos[MX], sufPos[MX];

int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n, k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
        cin>>ara[i];
    ll sum=0, idx=0;
    for(int i=1; i<k; i++)
        sum+=ara[i];

//    idx=1;
    for(int i=k; i<=n; i++)
    {
        sum += (ara[i] - ara[i-k]);
        pre[i] = sum;
//        preMX[i] = max(preMX[i-1], sum);
//        if(sum> preMX[i-1]) {
//            idx = i-k+1;
//        }
//        prePos[i] = idx;
    }

    sum=0;
    idx = n-k+1;

    for(int i=n; i>n-k+1; i--)
    {
        sum+= ara[i];
    }


    for(int i= n-k+1; i>0; i--)
    {
        sum += (ara[i] - ara[i+k]);
        suf[i] = sum;
        if(sum >= sufMX[i+1])
        {
            idx = i;
        }
        sufMX[i] = max(sufMX[i+1], sum);
        sufPos[i] = idx;
    }


//    for(int i=1; i<=n; i++)
//        cout<<pre[i]<<" ";
//    cout<<endl;
//    for(int i=1; i<=n; i++)
//        cout<<suf[i]<<" ";
//    cout<<endl;
//    for(int i=1; i<=n; i++)
//        cout<<sufMX[i]<<" ";
//    cout<<endl;
//    for(int i=1; i<=n; i++)
//        cout<<sufPos[i]<<" ";
//    cout<<endl;



    ll mx=0, temp;
    int ansl=1e9, ansr=1e9;
    for(int i=k; i<=n-k; i++)
    {
        ll l=0, r=0;
        temp = pre[i];
//        if(i>=k) {
//            l = preMX[i-k];
//        }

//        if(i+1<=n) {
        r = sufMX[i+1];
//        }
//        mx = max(mx, temp + max(l ,r));
//        cout<<"i "<<i<<" sum "<<temp+r<< " mx "<<mx<<endl;
        if(temp + r>= mx)
        {
            int templ = i-k+1;
            int tempr= sufPos[i+1];
//            cout<<"templ "<<templ<<" tempr "<<tempr<<endl;
//            if(l>r) {
//                tempr = prePos[i-k];
//            } else
//                tempr = sufPos[i+1];

            if(templ > tempr)
                swap(templ, tempr);
            if((temp + r> mx) || (templ<ansl) || (templ==ansl && tempr <= ansr))
            {
                mx = (temp + r);
                ansl = templ;
                ansr = tempr;
            }
            mx = temp + max(l,r);
        }
    }

    cout<<ansl <<" "<<ansr<<endl;

    return 0;
}


