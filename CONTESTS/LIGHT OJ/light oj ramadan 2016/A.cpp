#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
int disjoint[1000010];

int findPar(int r) {
    if(r== disjoint[r])
        return r;
    return disjoint[r] = findPar(disjoint[r]);
}
void setPar(int u, int v) {
    disjoint[findPar(u)] = findPar(v);
//    findPar(u);
}
int main ()
{

    int t,n;
    scanf("%d",&t);
    for(int k=1; k<=t; k++) {
        scanf("%d",&n);
        n*=2;
        for(int i=0; i<n; i++)
            disjoint[i]=i;
        n/=2;
        string s1,s2;
        int f1,f2;
        int cnt=0;
        for(int k=0; k<n; k++) {
            cin>>s1>>s2;

            if(mp.find(s1)==mp.end()) {
                mp[s1]=(cnt);
                f1= (cnt++);
            }
            else
                f1 = mp[s1];

            if(mp.find(s2)==mp.end()) {
                mp[s2]=(cnt);
                f2 = (cnt++);
            }
            else
                f2 = mp[s2];
//              printf("oka f1 %d f2 %d\n",f1,f2);
//              cout<<s1<<" "<<s2<<endl;
            setPar(f1,f2);
        }
        n=cnt;
        cin>>s1;
        int first = mp[s1];


        printf("Case %d: ",k);

        for(std:: map<string,int>:: iterator it = mp.begin(); it!=mp.end(); it++ ) {
            findPar(it->second);
        }
        first = disjoint[first];
        cnt=0;
        for(int i=0; i<n; i++) {
            if(disjoint[i]== first)
                cnt++;
        }
        printf("%d\n",cnt);
        if(k!=t)
            mp.clear();
    }
    return 0;
}


