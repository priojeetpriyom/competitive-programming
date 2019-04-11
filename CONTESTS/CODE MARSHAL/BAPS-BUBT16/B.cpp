#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myInput.txt","r",stdin);
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {
        string str;
        int k;
        map<string,int> mp;
        scanf("%d",&k);

        while(k--)
        {
            cin>>str;
            mp[str]++;
        }
        printf("Case %d: ",t);
        int mx=0;char temp,y;
        std::map<string,int>::iterator z;
        for(std::map<string,int>::iterator it= mp.begin(); it!= mp.end(); it++)  {
            int x = it->second;

            if(x > mx) {
                z = it;
                mx = it->second;
            }
        }
        cout<<z->first<<endl;
        mp.clear();
    }

    return 0;
}


