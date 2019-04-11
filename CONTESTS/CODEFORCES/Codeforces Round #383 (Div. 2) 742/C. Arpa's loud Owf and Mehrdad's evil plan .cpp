#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;

    int ara[111];
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int mn= -1;

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &ara[i]);

    for(int i=1; i<=n ;i++) {
        if(ara[i] == i)
            continue;

        int cnt=1;
        if(i == ara[ ara[i] ])
        {
            cnt =1;
            mn = max(mn, cnt);
            continue;
        }

        int dest = ara[i];
//        printf("i %d\n",i);
        while(dest!= i) {
//                printf("dest %d\n", dest);
            cnt++;
            if(dest == ara[dest] || cnt>101)
            {
//                printf("aise");
                printf("-1\n");
                return 0;
            }
            dest = ara[dest];

        }
        mn = max(mn, cnt);
    }
    printf("%d\n", mn);
    return 0;
}

