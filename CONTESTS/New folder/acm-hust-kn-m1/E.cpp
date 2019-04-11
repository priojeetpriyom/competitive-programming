#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    stack <string> backward,forwardd;
    string current,cmd;
    int t;
    scanf("%d",&t);
    getchar();
    for(int tcase=1; tcase<= t; tcase++)
    {
        printf("Case %d:\n",tcase);
        current = "http://www.lightoj.com/";
        while(cin>>cmd)
        {
            if(cmd == "VISIT")
            {
                backward.push(current);
                cin>>current;
                cout<<current<<"\n";
                while(!forwardd.empty())
                    forwardd.pop();
            }
            else if(cmd == "FORWARD")
            {
                if(forwardd.empty()) {
                    printf("Ignored\n");
                } else {
                    backward.push(current);
                    current = forwardd.top();
                    forwardd.pop();
                    cout<<current<<"\n";
                }
            } else if(cmd == "BACK")
            {
                if(backward.empty()) {
                    printf("Ignored\n");
                } else {
                    forwardd.push(current);
                    current = backward.top();
                    backward.pop();
                    cout<<current<<"\n";
                }
            }
            else
                break;
        }
        while(!backward.empty())
            backward.pop();
        while(!forwardd.empty())
            forwardd.pop();
    }

    return 0;
}
