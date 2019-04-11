#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main()
{
//        freopen("myIn.txt", "r", stdin);
//    freopen("myOut.txt", "w", stdout);

    char str[111];
    int len;
    scanf("%s", str);
    len  = strlen(str);
    string s;
    for(int i=0; i<len; i+=4) {
        if(str[i]!= '!')
        {
            s+=str[i];
            break;
        }
    }
    for(int i=1; i<len; i+=4) {
        if(str[i]!= '!')
        {
            s+=str[i];
            break;
        }
    }
    for(int i=2; i<len; i+=4) {
        if(str[i]!= '!')
        {
            s+=str[i];
            break;
        }
    }
    for(int i=3; i<len; i+=4) {
        if(str[i]!= '!')
        {
            s+=str[i];
            break;
        }
    }
//    cout<<s<<endl;

    for(int i=0 ;i<len; i++) {
        if(str[i] == '!') {
            cnt[i%4]++;
        }
    }

    for(int i=0; i<4; i++) {
        if(s[i]=='R') {
            printf("%d ", cnt[i]);
        }
    }
    for(int i=0; i<4; i++) {
        if(s[i]=='B') {
            printf("%d ", cnt[i]);
        }
    }
    for(int i=0; i<4; i++) {
        if(s[i]=='Y') {
            printf("%d ", cnt[i]);
        }
    }
    for(int i=0; i<4; i++) {
        if(s[i]=='G') {
            printf("%d\n", cnt[i]);
        }
    }

    return 0;
}






