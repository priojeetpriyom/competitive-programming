#include <bits/stdc++.h>
using namespace std;
//vector<int> vec;

int one[100], zero[100], mx= -1;
string getBin(int n) {
    string s;
//    printf("%d =>  ",n);

    do {
        s+= ((n&1) +'0');
        n = n>>1;
    } while(n>0);
    int len = s.length();
    if(len> mx)
        mx = len;


    for(int i=0; i<len/2; i++) {
        swap(s[i], s[len-i-1]);
    }
//        printf(" %s\n",s.c_str());
    return s;
}
void calc(int num) {
    string s;
    s=getBin(num);
//    char str[100];
//    strcpy(str, s.c_str());
//    printf("now %s\n",s.c_str());
//      printf("%d\n", s.length());

    int len = s.length();
    len = 64 - len;
    for(int i=len, j=0; i< 64; i++, j++)
    {
        if(s[j] == '1')
            one[i]++;
        else
            zero[i]++;
    }
    for(int i= len-1; i>=0; i--)
        zero[i]++;

//    for(int i=30; i< 64; i++)
//        printf("%d ", one[i]);
//    printf("one fin\n");
//    for(int i=30; i< 64; i++)
//        printf("%d ", zero[i]);
//    printf("\n");

//    printf("oka");
}
int getAns(int x) {
    string s = getBin(x);
    int len = s.length();
    int fix = 64 - len;
    int mn =INT_MAX;
//printf("len %d mx %d fix %d\n", len, mx, fix);
    for(int i=fix, j=0; i<64; i++, j++) {
        if(s[j]=='1') {
//              printf("%d %d\n", one[i],zero[i]);
            mn = min(mn, min(one[i], zero[i]) );
        } else {
//            printf("else %d %d\n", one[i],zero[i]);
            mn = min(mn, max(one[i]/2, zero[i]/2) );
            }
    }

    mx = 64-mx;
    for(int i=fix-1; i>=mx; i--) {
        mn = min(mn, max(one[i]/2, zero[i]/2) );
    }
    return mn;
}
int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n, x, num;
    scanf("%d %d", &n, &x);

    for(int i=0; i<n; i++) {
        scanf("%d", &num);
        calc(num);
    }
//    printf("okaxx");
    printf("%d\n", getAns(x));

    return 0;
}

