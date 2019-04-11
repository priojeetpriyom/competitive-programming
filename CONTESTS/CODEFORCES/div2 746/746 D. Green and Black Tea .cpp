#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    int x = max( ( (int)ceil((double)a/k)) -1, 0);
    int y = max( ( (int)ceil((double)b/k)) -1, 0);

    if(  x> b || y >a)
    {
        cout<<"NO";
        return 0;
    }
    string s;
    int i;
    if(a>b)
        i=1;
    else
        i=2;
    while(a>0 || b>0) {
        if(i%2==0) {
            b-=k;
            if(b<0) {
                cout<<"NO";
                return 0;
            }
            for(int j=0; j<k; j++)
                s+= "B";
            s+="G";
            a--;
            if(a<0) {
                cout<<"NO";
                return 0;
            }
        } else {
            a-=k;
            if(a<0) {
                cout<<"NO";
                return 0;
            }
            for(int j=0; j<k; j++)
                s+= "G";
            s+="B";
            b--;
            if(b<0) {
                cout<<"NO";
                return 0;
            }
        }
//        i++;
    }
    cout<<s;
    return 0;
}

