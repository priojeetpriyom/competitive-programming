#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//------------ loop macros

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)


//-------------- input macros

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cini0(i, n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}

#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}
#define cini1(i, n, ara) for(int i=1; i<=n; i++) {cin>>ar[i];}


#define si(n) scanf("%d", &n);
#define sii(n, m) scanf("%d %d", &n, &m);
#define siii(n, m, k) scanf("%d %d %d", &n, &m, &k);
#define siiii(n, m, k, o) scanf("%d %d %d %d", &n, &m, &k, &o);

#define sl(n) scanf("%lld", &n);
#define sll(n, m) scanf("%lld %lld", &n, &m);
#define slll(n, m, k) scanf("%lld %lld %lld", &n, &m, &k);
#define sllll(n, m, k, o) scanf("%lld %lld %lld %lld", &n, &m, &k, &o);

// ------------- BIT MANIPULATION ------------

#define CHECK(n, pos) ( (n& (1<<pos))>0)
#define SET(n,pos) (n | (1<<pos))



#define MX 500100
#define double long double
#define mod 1000000007
#define mod2 1000000009

vector<int> query[1<<13] [105];
ll cost[15], fre[1<<13];


int can[1<<13][105];
int ans[MX];

struct node {
    node* next[3];
    int cnt=0;
    node() {
        next[0]=next[1]= nullptr;
    }
};

node * root;
void change(int val, int rate) {
    root->cnt+= rate;

    int len=30;
//    for(int i=30; i>=0; i--)
//        if(CHECK(val, i)){
//            len = i;
//            break;
//        }
    node * cur = root;
    for(int i = len; i>=0; i--) {
        int next_val = CHECK(val, i);

        if(cur->next[next_val] == nullptr)
            cur->next[next_val] = new node();
        cur = cur->next[next_val];
        cur->cnt+= rate;
    }

    bool flag=false;
    cur= root;
    for(int i = len; i>=0; i--) {
        int next_val = CHECK(val, i);
        node *prev = cur;
        cur = cur->next[next_val];
        if(flag) {
            delete(prev);

        }
        else if(cur->cnt==0)
        {
            prev->next[next_val] = nullptr;
            flag = true;

        }

        if(flag && i==0){
            delete(cur);
        }

    }


}

int get_ans(int p, int l) {
//    for(int i=30; i>=0; i--) {
//        if(CHECK(l, i) && !CHECK(p, i)) {
//            return root->cnt;
//        }
//        else if(CHECK(p, i)) {
//            break;
//        }
//
//    }

    node * cur = root;
    int sum=0;
    for(int i=30; i>=0; i--) {
        if(cur->next[0] == nullptr && cur->next[1]== nullptr)
            return sum;

        int ldigit = CHECK(l, i);
        int pdigit = CHECK(p, i);

        if(ldigit) {
            int exor = pdigit ^ 1;
            if(exor==1) {
                //for handling xor with zero
                if(cur->next[0]!= nullptr)
                    sum+= cur->next[0]->cnt;


                if(cur->next[1]!= nullptr)
                    cur= cur->next[1];
                else
                    break;
            } else {
                if(cur->next[1]!= nullptr)
                    sum+= cur->next[1]->cnt;

                if(cur->next[0]!= nullptr)
                    cur= cur->next[0];
                else
                    break;
            }

        } else { //ldigit zero
            int exor = pdigit ^ 1;
            if(exor==1) {
                //for handling xor with zero

                if(cur->next[0]!= nullptr)
                    cur= cur->next[0];
                else
                    break;
            } else {
                if(cur->next[1]!= nullptr)
                    cur= cur->next[1];
                else
                    break;
            }
        }
    }

    return sum;
}

int main()
{
//    double time = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int q;
    si(q);

    root = new node();

    while(q--) {
        int x, p, l;
        sii(x, p);
        if(x==1) {
            change(p, 1);
        } else if(x==2) {
            change(p, -1);
        } else {
            si(l);
            printf("%d\n", get_ans(p, l));
        }
    }
//    cout<<(clock()-time)/CLOCKS_PER_SEC;

    return 0;
}
