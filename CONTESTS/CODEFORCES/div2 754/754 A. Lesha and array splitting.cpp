
#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n, sum=0, ara[1000];
    cin>>n;
    int ans[1000], len_ans=0;

    for(int i=0; i<n; i++)
        cin>>ara[i];
    int cnt=0;
    bool no = false;
    for(int i=0; i<n; i++) {
        sum+=ara[i];
    }

    if(sum == 0) {
        no = true;
        for(int i=0; i<n; i++) {
            sum-=ara[i];

            if(sum!=0) {
                cnt=2;
                ans[len_ans++] = 1;
                ans[len_ans++] = i+1;
                ans[len_ans++] = i+2;
                ans[len_ans++] = n;
                no = false;
                break;
            }
        }
    } else {
                cnt=1;
                ans[len_ans++] = 1;
                ans[len_ans++] = n;
    }

    if(no)
        cout<<"NO";
    else {
        printf("YES\n%d\n", cnt);
        for(int i=0; i<len_ans ; i++)
        {
            printf("%d ",ans[i]);
            i++;
            printf("%d\n",ans[i]);
        }
    }

    return 0;
}
