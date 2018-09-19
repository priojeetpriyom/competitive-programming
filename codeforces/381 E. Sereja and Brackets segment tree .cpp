#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef  long long ll;

string s;

struct node {
    int open=0, close=0;
};

struct node tree[1000005<<2];


node build(int b, int e, int node) {
    struct node &t = tree[node];

     if(b==e) {
        if(s[b-1] == '(') t.open=1;
        else t.close=1;
        return t;
     }


     int left = node<<1;
     int right = left+1;
     int mid = (b+e)>>1;

     struct node l,r;
     l = build(b, mid, left);
     r = build(mid+1, e, right);

     int x = min(l.open, r.close);
     l.open-=x; r.close-=x;

     t.open  = l.open + r.open;
     t.close = l.close + r.close;

    return t;


}
    int start,finish;

node query(int b, int e, int node) {
    struct node  t = tree[node];
    if(b>finish || e<start) {
        struct node x;
        return x;
    };

    if(b>=start && e<=finish) {
//        printf("b %d e %d t %d\n", b, e, t.open+t.close);
        return t;
    }


     int left = node<<1;
     int right = left+1;
     int mid = (b+e)>>1;


     struct node l,r;
     l = query(b, mid, left);
     r = query(mid+1, e, right);

     int x = min(l.open, r.close);
     l.open-=x; r.close-=x;

     t.open  = l.open + r.open;
     t.close = l.close + r.close;

    return t;

}




int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    std::ios_base::sync_with_stdio(false);    cin.tie(0);

    cin>>s;
    build(1, s.size(), 1);

    int m;

    cin>>m;
    while(m--) {
        cin>>start>>finish;
        node x = query(1, s.size(),1);
        cout<<(finish-start+1)-x.open - x.close<<endl;
    }



    return 0;
}

