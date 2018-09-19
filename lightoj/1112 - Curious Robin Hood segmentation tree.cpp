#include <bits/stdc++.h>
using namespace std;

int ara[100010],tree[300010];

void init(int node, int b, int e) {

    if(b==e) {
        tree[node] = ara[b];
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;

    init(left, b, mid);
    init(right, mid+1, e);

    tree[node] = tree[left] + tree[right];
}

int new_money,s,f,amount;
void update(int node, int b, int e) {

    if(b==e && b==s) {
        if(new_money==0)
        {
            amount=tree[node];
            tree[node] = 0;
        }
        else
            tree[node]+= new_money;
        return;
    }

    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;

    if(s<=mid) {
        update(left,b, mid);
    } else
        update(right,mid+1, e);
    tree[node] = tree[left] + tree[right];
}

int find_sum(int node, int b, int e) {
    if(b==e)
    {
        return tree[node];
    }
    if(b>f || e<s)
        return 0;
    if(b>=s && e<=f)
        return tree[node];

    int left = node*2;
    int right = left+1;
    int mid = (b+e)/2;
    int sum1=0;
    int sum2=0;
    if(s<=mid) {
        sum1 = find_sum(left, b, mid);
    }
    if(f>mid) {
        sum2 = find_sum(right, mid+1, e);
    }
    return sum1+sum2;
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int tc=1; tc<=t; tc++) {
        int n, q;
        scanf("%d %d",&n, &q);
        printf("Case %d:\n",tc);

        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);
        init(1,1,n);
        int x;
        for(int i=0; i<q; i++) {
            scanf("%d",&x);
            if(x==1) {
                scanf("%d",&s);
                s++;
                f=s;
                new_money=0;
                update(1,1,n);
                printf("%d\n",amount);
            } else if(x==2) {
                scanf("%d %d",&s,&new_money);
                s++;
                f=s;

                update(1,1,n);
            } else {
                scanf("%d %d", &s, &f);
                s++;f++;
                printf("%d\n",find_sum(1,1,n));
            }
        }
    }

    return 0;
}

