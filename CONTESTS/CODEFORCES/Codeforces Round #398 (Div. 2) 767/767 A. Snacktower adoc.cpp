#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
//    freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);


    int n;
    map<int, int> mp;

    cin>>n;
    int x;
    int idx=n;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(x == idx) {
            printf("%d ",x);
            idx--;
            while(mp.find(idx) != mp.end() && mp[idx] == 1) {
                printf("%d ",idx);
                mp[idx] = -1;
                idx--;
            }
        } else
            mp[x] =1;

        if(i == n-1)
            while(idx>0)
        {
            printf("%d ",idx);
            idx--;
        }
        printf("\n");
    }
    return 0;


}


