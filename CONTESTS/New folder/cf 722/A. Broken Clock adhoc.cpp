#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d",&n);
    int hour,minit,cnt=0;
    char c;
    char str[10];
//    scanf("%d \n%c %d",&hour, &c, &minit);
    scanf("\n%s", str);
    if(n==12) {
        if(str[0] == '0' && str[1] == '0') {
            str[0] = '1';
        }
        else if(str[0] == '1' && str[1] >'2')
            str[1]='2';
        else if(str[0]>'1')
        {
            if(str[1] <='2')
                str[0] = '1';
            else
                str[0] = '0';

        }
    } else {
        if(str[0] > '2')
            str[0] = '1';
        else if(str[0] == '2' && str[1] > '3')
            str[1] = '3';
    }

    if(str[3]> '5')
        str[3] = '3';

    printf("%s\n",str);

    return 0;
}
