#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

struct node {
    char c;
    int val;
    int pos;
} ara[10];
int len;


bool cmp(node a, node b) {

    return a.pos<b.pos;
}


int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans=0;


    int n;
    cin>>n;
    char c;
    int val;
    cin.ignore();


    for(int loop=1; loop<=n; loop++) {
        cin>>c>>val;
        int pos = -1;
        for(int i=0; i<len; i++) {
            if(ara[i].c == c) {
                pos = i;
            }
        }


        if(pos !=-1) {
            if(c == '|')
                ara[pos].val = ara[pos].val | val;
            else if(c== '^' ) {
                ara[pos].val = ara[pos].val ^ val;
            } else
                ara[pos].val = ara[pos].val & val;

        } else {
            pos= len;
            ara[len].c = c;
            ara[len].val = val;


            if(c=='|')
                ara[len].pos =   ;
            if(c=='&')
                ara[len].c='|';
            if(c=='|')
                ara[len].c='|';


            len++;
         }




    }
    sort(ara, ara+len, cmp);

    cout<<len<<endl;
    for(int i=0; i<len;  i++) {
        cout<<ara[i].c<<" "<<ara[i].val<<endl;
    }



    return 0;
}


