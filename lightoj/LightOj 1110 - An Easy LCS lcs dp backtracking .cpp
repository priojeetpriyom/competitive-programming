#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

char str1[111], str2[111];
int xxx,  len1, len2;

char ans_str[111],path[111];
int len_path, len_ans=0;
int visited[111][111];
string pre[105][105];


string cmp(string a, string b) {

    if(a.size()> b.size()) return a;
    if(a.size() == b.size() && a<b) return a;

    return b;

}


string lcs(int pos1, int pos2) {

    if(pos1==len1 || pos2 == len2) {
        return "";
    }

//    int &ret = dp[pos1] [pos2];

    if(visited[pos1] [pos2] == xxx) {
        return pre[pos1] [pos2];
    }
    visited[pos1] [pos2] = xxx;



    if(str1[pos1] == str2[pos2]) {
//        path[len_path++] = str1[pos1];
        pre[pos1][pos2] = str1[pos1] + lcs(pos1+1, pos2+1);
//        path[len_path--] = '\0';

    }else  {

        pre[pos1] [pos2] = cmp(lcs(pos1+1, pos2), lcs(pos1, pos2+1));

    }
//    printf("pos1 %d pos2 %d pre %s\n", pos1, pos2, pre[pos1][pos2].c_str());
    return pre[pos1] [pos2];
//    return ret;


}



int main()
{

//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        xxx++;
        scanf("\n%s \n%s", str1, str2);
//        printf("%s %s\n", str1, str2);
        len1= strlen(str1), len2 = strlen(str2);

            printf("Case %d: ",tc);
        string ans = lcs(0, 0);
        if(ans.size() == 0)
            printf(":(\n");
        else {
//            printf("ans %d\n", ans);
            xxx++;
//            generate_path(0, 0);
            printf("%s\n", ans.c_str());
        }
        len_ans = len_path=0;
//        memset(path, 0, sizeof path);
//        memset(ans_str, 0, sizeof ans_str);
    }


    return 0;

}

