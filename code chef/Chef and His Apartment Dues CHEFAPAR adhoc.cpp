#include<bits/stdc++.h>
using namespace std;

int n;
int ara[100100];

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--) {
        cin>>n;

        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }
        bool fine=false;
        int sum=0;
        for(int i=0; i<n; i++) {
            if(fine)
                sum+=100;
            else if(ara[i]==0) {
                fine= true;
                sum+=100;
            }
            if(ara[i]==0)
                sum+=1000;
        }
        cout<<sum<<endl;

    }
    return 0;

}


