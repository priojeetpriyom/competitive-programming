#include <bits/stdc++.h>
using namespace std;

struct node
{
    long long sum;
    int par=0;
} group[100011];
long long mx=0;
long long del_sec[100011];

int find_par(int n) {
    if(n == group[n].par)
        return n;

    return group[n].par = find_par(group[n].par);
}

int merge_group(int u, int v) {
    int x = find_par(u);
    int y = find_par(v);
    group[y].sum += group[x].sum;
    group[x].par = y;
    find_par(u);
    return y;
}

int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&group[i].sum);
//        group[i].par =i;
    }

//    init(1,1,n);
//    printf("oka");
    int x;
    for(int i=0; i<n; i++)
    {
        scanf("%I64d", &del_sec[i]);
    }

    for(int i=n-1; i>=0; i--) {
        int par,s;
        s = del_sec[i];
        if(group[s-1].par != 0 && group[s+1].par != 0) {
            par = merge_group(s-1, s+1);
            group[par].sum += group[s].sum;
            group[s].par= par;
        } else if(group[s+1].par !=0){
            par = find_par(s+1);
            group[par].sum += group[s].sum;
            group[s].par= par;
        } else if(group[s-1].par!=0 ) {
            par = find_par(s-1);
            group[par].sum += group[s].sum;
            group[s].par= par;
        } else {
            group[s].par = s;
            par = s;
        }
//        printf("par %d\n",par);
        del_sec[i] = mx;
        mx = max(mx, group[par].sum);
    }

    for(int i = 0; i<n; i++)
        printf("%I64d\n", del_sec[i]);

    return 0;
}
