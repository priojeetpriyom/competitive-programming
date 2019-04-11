#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct my
{
    ll be;
    ll af;
    bool x=false;
} a[1010];


int main()
{
    ll t, i, j, n, len, val,cs = 0,  pw, k;
    string str;

    cin >> t;
    while(t--)
    {
        cin >> n;
        getchar();
        getline(cin, str);
        len = str.size();

        j = 0;
        for(i=0; i<len; i++)
        {
            bool x = false;
            val = 0;
            pw = 0;
            while(str[i] != '*')
            {
                if(str[i] =='X') x=true;
                if(str[i] == '+')
                {
                    break;

                }
                if(str[i] == 'X' || i == len) break;
                if(str[i] >= '0' && str[i] <='9')
                {
                    val *=10;
                    val += str[i]-'0';
                }
                i++;
            }
            bool dukhsi = false;
            while(str[i] != '+')
            {
                if(str[i] =='X') x=true;
                if(i==len) break;
                if(str[i] >= '0' && str[i] <='9')
                {
                    dukhsi = true;
                    pw *= 10;
                    pw += str[i]-'0';
                }
                i++;
            }

            a[j].be = max((ll)1, val);
//            if()
            a[j].af = max((ll) ( (dukhsi==false) && (x) ), pw);
//            printf("j %d af %d\n",j, a[j].af );
            a[j].x = x;
            j++;
////            cout << " i " << i << endl;
        }

//        printf("j %d\n", j);
        /* for(i=0; i<j; i++)
         {
             cout << a[i].be << " " <<a[i].af << endl;
         }*/

    for(i=0; i<j; i++)
    {
        ll val2 = a[i].af;
        for(k= a[i].af; k>a[i].af - n; k--)
        {
            a[i].be *= val2;
            val2--;
        }
        a[i].af = val2;
    }
    printf("Case %lld: ", ++cs);
    /*if(n==0) {
        cout<<str<<endl;
        continue;
    }*/
    if(j == 1)
    {
        if(a[0].x == false){
            printf("0\n");
            continue;
        }

    }
    bool st = true;
    for(i=0; i<j; i++)
    {
        if(a[i].be != 0)
        {
//            printf("aise\n");
            if(st)
            {
                st = false;
            }
            else
                printf(" + ");

            if(a[i].be != 1 || a[i].af == 0)
            {
                printf("%lld", a[i].be);
            }
            if(a[i].af == 1)
            {
                if(a[i].be > 1) printf("*");
                printf("X");
            }
            else if(a[i].af>1)
            {
                if(a[i].be > 1) printf("*");
                printf("X^%lld", a[i].af);
            }
        }
    }
    if(st)
    {
        cout << "0\n";
    }
    else
        cout << endl;
    }
}
