#include <bits/stdc++.h>

using namespace std;
typedef long long ll;





int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    char str[] = "0^>v<^>v<^>v<";

    char start, endd;
    cin>>start>>endd;
    int n;
    cin>>n;

    int pos=0;
    for(int i=5; ; i++)
        if(start == str[i])
        {
            pos = i;
            break;
        }

    if(n==0)
    {
//        if(start == endd)
            cout<<"undefined"<<endl;
        return 0;
    }
    n%=4;
//    if(n==0) n==4;
    if(n==0)
    {
        cout<<"undefined"<<endl;
    }
    else if(str[pos-n] == endd && str[pos+n]==endd)
        cout<<"undefined"<<endl;
    else if(str[pos-n] == endd ) cout<<"ccw"<<endl;
    else cout<<"cw"<<endl;



    return 0;
}


