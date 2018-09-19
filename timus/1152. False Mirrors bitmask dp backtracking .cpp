#include <bits/stdc++.h>
//#include <iostream>
using namespace std;
typedef long long ll;
int n;
int dp[1<<20], ara[21];

int CHECK(int mask, int pos) {
    return mask & (1<<pos);
}
int SET(int mask, int pos) {
    return mask | (1<<pos);
}
int RESET(int mask, int pos) {
    return mask & (~(1<<pos));
}


int set_middle(int mask, int pos) {

        mask = SET(mask, pos);
        if(pos==0) mask = SET(mask, n-1);
        else mask = SET(mask, pos-1);

        if(pos==n-1) mask = SET(mask, 0);
        else mask = SET(mask, pos+1);



    return mask;
}

int reset_middle(int mask, int pos) {
        mask = RESET(mask, pos);
//        printf("mask1 %d\n", mask);
        if(pos==0) mask = RESET(mask, n-1);
        else mask = RESET(mask, pos-1);
//        printf("mask2 %d\n", mask);

        if(pos==n-1) mask = RESET(mask, 0);
        else mask = RESET(mask, pos+1);
//        printf("mask3 %d\n", mask);



    return mask;
}


//int set_left(int mask, int pos) {
//    for(int i=0; i<3; i++) {
//        mask = SET(mask, pos);
//        if(pos==0) pos = n-1;
//        else pos--;
//    }
//    return mask;
//}
//
//int reset_left(int mask, int pos) {
//    for(int i=0; i<3; i++) {
//        mask = RESET(mask, pos);
//        if(pos==0) pos = n-1;
//        else pos--;
//    }
//    return mask;
//}
//int set_right(int mask, int pos) {
//    for(int i=0; i<3; i++) {
//        mask = SET(mask, pos);
//        if(pos==n-1) pos = 0;
//        else pos++;
//    }
//    return mask;
//}
//
//int reset_right(int mask, int pos) {
//    for(int i=0; i<3; i++) {
//        mask = RESET(mask, pos);
//        if(pos==n-1) pos = 0;
//        else pos++;
//    }
//    return mask;
//}

int calc_damage(int mask) {
    int sum=0;
    for(int i=0; i<n; i++) {
        if(CHECK(mask, i))
            sum+=ara[i];
    }
    return sum;
}


int rec(int mask) {
    if(!mask) return 0;
    int &ret = dp[mask];
    if(ret!= (1<<28)) return ret;

//    printf("mask %d\n", mask);
    for(int i=0; i<n; i++) {
        if(CHECK(mask, i)) {
//            printf("i %d\n", i);
//            mask = reset_left(mask, i);
//            ret = min(ret, rec(mask) + calc_damage(mask));
//            mask = set_left(mask, i);
//            int track = mask;
//            mask = reset_middle(mask, i);
            ret = min(ret, rec(reset_middle(mask, i)) + calc_damage(reset_middle(mask, i)));
//            mask = track;

        }
    }
    return ret;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>n;
    int mask=0;
    for(int i=0; i< (1<<n); i++) dp[i] = (1<<28);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &ara[i]);
        mask = SET(mask, i);
    }
    cout<<rec(mask)<<endl;
    while(cin>>n) {
        cout<<dp[n]<<endl;
    }
//    printf("mask %d\n", 127);
//    n=7; cout<<reset_middle(127, 1);
    return 0;
}





