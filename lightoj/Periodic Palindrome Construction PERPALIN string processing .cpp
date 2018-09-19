#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pll;
#define MX 100100

char str[MX];


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;

    scanf("%d", &t);

    while(t--) {
        int len, interval;

        cin>>len>>interval;
        str[len+1] = '\0';

        for(int i=1; i<=len; i++)
            str[i] = 'b';

        for(int i=1; i<=len; i+=interval) {
            str[i] = 'a';
        }

        for(int i=1; i<=len/2; i++) {
            if(str[i]=='a') {
                str[len - i +1] = 'a';
            }
            else if(str[len - i +1] == 'a')
                str[i] = 'a';
        }
//        for(int i = len/2+1; i<len; i++) {
//            if(str[i]=='a') {
//                str[i -(i - len/2 )] = 'a';
//            }
//        }



        bool valid = false;


        for(int i=1; i<=len; i++)
            if(str[i]=='b')
        {
            valid = true;
            break;
        }

        if(valid)
            cout<<str+1<<endl;
        else
            printf("impossible\n");

    }


    return 0;
}

