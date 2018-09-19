#include <bits/stdc++.h>

using namespace std;
int ara[100100];
vector<int>cal(100100);
int main() {
    int n;
    scanf("%d", &n);
    int x;
    //int cnt=0;
    // int y=-1;
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        // if(!cal[ara[i]].size())
        //     cal[ara[i]].push_back(0);
        cal[i] = cal[i-1]^x;
        // cal[ara[i] ].push_back(i);

       // if(x>mx_num) mx_num =x;
    }


    if(cal[n-1]) printf("%d\n", n);
    else {
        int left=n, right=n;
        for(int i=0; i<n; i++) {
            if(cal[i]) {
                left = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(cal[i]) {
                right = i;
                break;
            }
        }
                printf("%d\n", n - min(left+1, right));
    }

    //printf("mx_num %d\n", mx_num);



    // int f=1;
    // for(int i=1; i<=mx_num; i++) {

    //     //printf("i %d ara %d mx %d\n", i, ara[i], mx_num);
    //     if(ara[i]&1) {

    //         f=0;
    //         break;
    //     }
    // }

    // if(f) {
    //     //printf("aise\n");
    //     for(int i=1; i<=mx_num; i++) {
    //     if(ara[i]>1 && ara[i]%2==0) {
    //         //mn=-1;
    //         ara[i]--;
    //         break;
    //     }
    // }
    // }
    // //printf("f %d y %d\n", f, y);
    // if(!f && y) {

    //     //printf("y %d\n", y);
    //     printf("%d\n", n);
    // }
    // else {
    //     printf("%d\n", n-1);
    // }


    return 0;
}
