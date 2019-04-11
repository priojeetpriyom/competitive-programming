#include <bits/stdc++.h>
using namespace std;

char str[111];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    int n;
    scanf("\n%s", str);
    n = strlen(str);
//    printf("%d %d\n", abs(str[0] - 'a'), abs('a'+26 - str[0] ));
    int sum = min(abs(str[0] - 'a'), abs('a'+26 - str[0] ));


    for(int i=1; i<n; i++) {
        sum += min(abs(str[i]-str[i-1]), abs(26- abs(str[i] - str[i-1]) ));
//        cout<<"sum "<<sum<<endl;
    }

    printf("%d\n", sum);

    return 0;
}
