#include <bits/stdc++.h>
using namespace std;


int usb[300100], ps2[300100], lenUsb=0, lenPs2=0;
int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    int a,b,c, m;
    cin>>a>>b>>c>>m;

    int x;
    char str[100];
    for(int i=0 ;i<m ; i++)
    {
        scanf("%d \n%s", &x, str);
        if(str[0] == 'U')
            usb[lenUsb++] = x;
        else
            ps2[lenPs2++] = x;
    }
//    for(int i=0; i< max(lenUsb, lenPs2); i++)
//        printf("us %d ps %d\n", usb[i], ps2[i]);


    sort(usb, usb+lenUsb);
    sort(ps2, ps2+lenPs2);
    long long sum=0;
    int u=0, p=0;
    int cnt=0;
    for(int i=0; i<a && u<lenUsb; i++) {
        sum+= usb[u++];
        cnt++;
    }

    for(int i=0; i<b && p< lenPs2; i++) {
        sum+= ps2[p++];
        cnt++;
    }
//    printf("sum %lld\n", sum);
    usb[lenUsb] = INT_MAX;
    for(int i=0; i<c; i++) {
        if(p!=lenPs2 && ps2[p] <=usb[u]) {
            sum+= ps2[p++];
        } else if(u != lenUsb) {
            sum+= usb[u++];
        } else
            break;
        cnt++;
    }

    cout<<cnt<<" "<<sum;

    return 0;
}









