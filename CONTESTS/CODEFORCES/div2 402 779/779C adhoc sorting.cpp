#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, a[200100], b[200100], k;

struct node {
 int pos, dif;

 bool operator< (const node& right) const { return dif < right.dif;}

};

struct node diff[200100];


//bool comp(node a, node b) {
//    return a.val > b.val;
//}

int main()
{
    cin>>n>>k;

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &b[i]);

    }


    for(int i=0; i<n; i++) {
        diff[i].dif = a[i] - b[i];
        diff[i].pos = i;
    }

    sort(diff, diff+n);
//    cout<<a[diff[0].pos ]<<endl;

    int i;
    long long cost=0;
    for(i =0; i<k; i++) {
        cost+= a[diff[i].pos ];
    }

    for( i ; i<n; i++)
    {
        if(diff[i].dif < 0 ) {
            cost+= a[diff[i].pos ];
        } else
            break;
    }
    for( i ; i<n; i++)
    {
        cost+= b[diff[i].pos];
    }

    cout<<cost<<endl;


    return 0;
}
