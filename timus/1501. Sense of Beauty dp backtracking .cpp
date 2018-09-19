#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
char seq_one[1010], seq_two[1010];
int dp[1011] [1011] [4], dir[1011] [1011] [4];

int rec(int one, int two, int prev) {
//    printf("one_pos %d two_pos %d prev %d\n", one, two, prev);
    if(one>n || two>n) return 0;
    if(one==n && two==n) return 1;
    int &ret= dp[one] [two] [prev];
    int &d = dir[one] [two] [prev];
    if(ret!= -1) return ret;

    if(prev!= seq_one[one] -'0')
    {
        ret = rec(one+1, two, seq_one[one] -'0');
        d = 1;
    }
    if(prev != seq_two[two]-'0')
    {
        int x = rec(one, two+1, seq_two[two]-'0');
        if(x> ret) {
            ret = x;
            d = 2;
        }
    }
    return ret;
}

void print_path(int one, int two, int prev){
    while(one<n || two<n) {
        printf("%d", dir[one] [two][prev]);
        if(dir[one] [two] [prev]==1)
        {
            prev= seq_one[one] -'0';
            one++;
        }
        else
        {
            prev= seq_two[two]-'0';
            two++;
        }
    }
    printf("\n");
}


int main()
{
    //timus.ru 1501. Sense of Beauty

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    memset(dp, -1, sizeof dp);
    cin>>n>>seq_one>>seq_two;
//    printf("%s\n%s\n",seq_one, seq_two);
    printf("%d\n", rec(0,0,2));
//    if(rec(0,0,2)==1)
//       print_path(0,0,2);
//    else
//        printf("Impossible\n");



    return 0;
}





