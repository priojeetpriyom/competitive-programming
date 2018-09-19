#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


vector<pair<int, int> > vec (1000010);


int main()
{


//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int n,q;

    cin>>n>>q;

    int nn = round(ceil(sqrt(n)* ceil(sqrt(n)) ));
    nn = n*n;
    int dir_r[] = {0, 1, 0, -1};
    int dir_c[] = {1, 0, -1, 0};
    int cnt=1, dir=0;
    int r=1, c=1;
    while(nn)
    {
//        if(nn==2) {
//            vec[1] = make_pair(r, c-1);
//            break;
//        }

//        printf("nn %d\n", nn);
        int root = sqrt(nn);
        vec[nn] = make_pair(r,c);
        for(int i=1; i<root; i++)
        {
            r+= dir_r[dir];
            c+=dir_c[dir];

            nn--;
//            printf("r %d c %d nn %d\n", r, c, nn);
            vec[nn] = make_pair(r, c);
        }

        dir = (dir+1) % 4;


        for(int i=1; i<root; i++)
        {
            r+= dir_r[dir];
            c+=dir_c[dir];
            nn--;
            vec[nn] = make_pair(r, c);
        }
        nn--;
        dir = (dir+1) % 4;
        r +=dir_r[dir];
        c+= dir_c[dir];

//        r+= dir_r[dir];
//        c+=dir_r[dir];
//        nn--;
//        vec[nn] = make_pair(r, c);

    }
    int x;
    while(q--) {
        scanf("%d", &x);
        printf("%d, %d\n",vec[x].first, vec[x].second );
    }



    return 0;

}
