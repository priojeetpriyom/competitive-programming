#include <bits/stdc++.h>
using namespace std;

int ara[100005];
map<int,bool>mp;
int main()
{
//    freopen("myOutput.txt","w",stdout);

    int n,m;
    scanf("%d %d",&n,&m);
        int x;

    for(int i=0; i<n; i++) {
        scanf("%d",&ara[i]);
    }
    mp[ara[n-1]]=1;
    ara[n]=1;
    for(int i=n-1; i>=0;i--) {
        x = ara[i];
        if(mp[x]) {

            ara[i] = ara[i+1];
        }else {

            ara[i] = ara[i+1] + 1;
            mp[x]=1;
        }
    }

//    for(int i=0; i<n; i++)
//        printf("%d ",ara[i]);


    while(m--) {

        scanf("%d",&x);
        printf("%d\n",ara[x-1]);
    }
    return 0;
}

