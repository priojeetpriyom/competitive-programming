#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int ara[1111] , temp[1111];

int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {
        int n, k,sum;
        cin>>n>>k;
//        sum = (n+1)/2;
        int mx=0, mid;
        bool even=false;

        for(int i=1; i<=n; i++) {
            cin>>temp[i];
        }
        sort(temp+1, temp+n+1);


        if(n&1)
        {
            for(int i=1; i<=n; i++)
            {
                ara[i] = temp[i];
            }
            mid = (n/2)+1;

        }
        else
        {
            even=true;
            for(int i=1, j=1; i<=n+1; i++, j++)
            {
                ara[i] = temp[j];
                if(i == n/2) i++;
            }
            mid = (n/2)+1;
            ara[mid]=0;
            k++;
            n++;
        }

//        printf("mid %d k/2 %d\n", mid, k/2);
//        for(int i=1; i<=n; i++)
//            printf("%d ", ara[i]);
//            printf("\n");
//        {
//            for(int i = mid; i>= max(mid-(k/2), 1); i--)
//            {
//                mx = max(mx, ara[i]);
//            }
//            for(int i = mid; i<= min(mid+(k/2), n); i++)
//            {
////                printf("i %d mid %d ara[i] %d\n", i,mid, ara[i]);
//                mx = max(mx, ara[i]);
//            }
//        }


        cout<<ara[ min(n, mid+ (k/2))] <<endl;



    }


    return 0;
}


