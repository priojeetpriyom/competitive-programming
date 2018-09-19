#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct node
{
    int a,b;
    ll height;
} rings[100100];

int n;
ll dp[100100], ans[100100];

bool cmp(node a, node b)
{
//    if(a.b > b.a && a.b <= b.a) return false;
//    if(a.b > b.a || b.b > a.b)  return false;
    if(a.b> b.b)
        return true;
    if(a.b == b.b && a.a > b.a)
        return true;
    return false;
}

//ll rec(int pos, node prev)
//{
//    if(pos == n)
//        return 0;
//
//    ll &ret = dp[pos];
//
//
////    printf("CALLING FOR %d prev_a %d\n", pos+1, prev.a);
//
//    if(rings[pos].b > prev.a && rings[pos].b <= prev.b)
//    {
////        if(prev.b == INT_MAX)
////            printf("PICKED %d\n",pos+1);
//
//        if(ret != -1)
//        {
////            printf("returned dp %I64d\n", ret);
//            return ret;
//        }
//
//        ret = rec(pos+1, rings[pos]) + rings[pos].height;
////        printf("RETURNED %I64d from pos %d\n", ret, pos);
//    }
//    ll x = rec(pos+1, prev);
////    printf("RETURNED %I64d POS %d\n",x, pos);
//    return max(ret, x);
//}

int main()
{
    //    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin>>n;

    for(int i=0; i<n; i++)
        scanf("%d %d %I64d", &rings[i].a, &rings[i].b, &rings[i].height);

    sort(rings, rings+n, cmp);


//    for(int i=0; i<n; i++)
//    {
//        cout<<rings[i].a<<"  "<<rings[i].b<<"  "<<rings[i].height<<endl;
//    }

    stack<int> s;

    for(int i=0; i<n; i++) {
        while(!s.empty() && rings[s.top()].a >= rings[i].b)
            s.pop();

        if(!s.empty())
            ans[i] = ans[s.top()];

        ans[i] += rings[i].height;
        s.push(i);

    }
    ll mx = INT_MIN;
    for(int i=0; i<n; i++)
        mx = max(mx, ans[i]);

    cout<<mx;





//
//    struct node temp;
//    temp.a = INT_MIN;
//    temp.b = INT_MAX;
//    temp.height =0;
//    cout<<rec(0, temp);
////    cout<<rec(0, temp);
//
//
//    printf("\ndp\n");
//    for(int i=0; i<n; i++)
//        printf("%I64d\n", dp[i]);

    return 0;
}



