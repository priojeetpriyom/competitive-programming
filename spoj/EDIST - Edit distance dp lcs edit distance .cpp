#include<bits/stdc++.h>

using namespace std;

int n=1, dp[2005] [2005], visited[2005] [2005], len1, len2;
char str1[2020], str2[2020];
    int t;

int rec(int len_a, int len_b) {
    if(len_a==len1 && len_b==len2) return 0;
    if(len_a== len1) return len2-len_b;
    if(len_b == len2) return len1 - len_a;

    int &ret = dp[len_a] [len_b];
    int &vis = visited[len_a] [len_b];
    if(vis==t) return ret;
    vis = t;
//    ret = 1e6;
    ret = min(rec(len_a+1, len_b) , rec(len_a, len_b+1))+1;
    ret = min(ret, rec(len_a+1, len_b+1)+ (str1[len_a]!=str2[len_b]));

    return ret;

}


int main(){


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    cin>>t;

    while(t) {
//        memset(dp, -1, sizeof dp);
        scanf("\n%s \n%s",str1, str2);
        len1 = strlen(str1), len2 = strlen(str2);
        cout<<rec(0, 0)<<endl;
        t--;
    }
}

