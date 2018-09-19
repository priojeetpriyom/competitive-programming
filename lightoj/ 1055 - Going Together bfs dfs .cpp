///call a  bfs to compute if three robots fall in exit simultaneously. if they do then take minimum from all of this cases.
///constraints are: no two robots can be in same position/at '#' / out of board at any time.


#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MX 10


struct node
{
    int ar, br, cr, ac, bc, cc,cost=0;
    node()
    {
    }
    node(int arr, int acc, int brr, int bcc, int crr, int ccc, int cost)
    {
        ar = arr;
        br = brr;
        cr = crr;
        ac = acc;
        bc = bcc;
        cc = ccc;
        this->cost = cost;
    }
};
char grid [MX] [MX];
//const int reached = 15;
int n, tc;
//struct node


int vis[MX][MX] [MX] [MX] [MX] [MX];
int xx=0;

int dirr[] = {-1, 0, 1, 0}, dirc[] = {0, 1, 0, -1};
int mn;


int bfs(node start)
{
//    xx++; ///used to avoid memset of vis
//    memset(vis, 0, sizeof vis);
    queue<struct node > Q;
    Q.push(start);
//
    while(!Q.empty())
    {
//        printf("q size %d\n", Q.size());
        node cur  = Q.front();
        Q.pop();
        int ar, br, cr, ac, bc, cc;
        ar = cur.ar;
        br = cur.br;
        cr = cur.cr;
        ac = cur.ac;
        bc = cur.bc;
        cc = cur.cc;

//        printf("ar %d ac %d br %d bc %d cr %d cc %d %c\n", ar, ac, br, bc, cr, cc, grid[cr][cc]);
//        if(ar<0 || ar==n || ac<0 || ac==n || br<0 || br==n || bc<0 || bc==n || cr<0 || cr==n || cc<0 || cc==n || grid[ar][ac] =='#' || grid[br][bc] =='#' || grid[cr][cc] =='#')
//            continue;

//        if(vis[ar][ac][br][bc][cr][cc]==tc)
//        {
////            printf("already visited\n");
//            continue;
//        }
        if((ar==br&& ac==bc)) // && grid[ar][ac]!= 'X')
            continue;
        if((ar==cr&& ac==cc)) // && grid[ar][ac]!= 'X')
            continue;
        if((br==cr&& bc==cc)) // && grid[br][bc]!= 'X')
            continue;


//        vis[ar][ac][br][bc][cr] [cc] = tc;


//        printf("ok\n");

        if(grid[ar][ac] =='X' && grid[br][bc] =='X' && grid[cr][cc] =='X')
        {
//            if((ar==br&& ac==bc) || (ar==cr&& ac==cc) || (br==cr&& bc==cc)) {
//
//            } else
            {
                mn = min(mn, cur.cost);
                continue;
            }

        }

        for(int i=0; i<4; i++)
        {
            int arr=ar, acc=ac, brr=br, bcc=bc, crr=cr, ccc=cc;

//            if(grid[arr][acc]!='X') {
            arr = ar + dirr[i];
            acc = ac + dirc[i];
//            if(arr<0 || arr==n || acc<0 || acc==n || grid[arr][acc]=='#')
//            {
//                arr = ar;
//                acc = ac;
//            }
//            } else if((arr == brr && acc == bcc) || (arr == crr && acc == ccc)) {
//                arr = ar + dirr[i];
//                acc = ac + dirc[i];
//            }
//            if(grid[br][bc]!='X') {
            brr = br + dirr[i];
            bcc = bc + dirc[i];
//            if(brr<0 || brr==n || bcc<0 || bcc==n || grid[brr][bcc]=='#' || (brr==arr && bcc == acc))
//            {
//                brr = br;
//                bcc = bc;
//            }
//            } else if((arr == brr && acc == bcc) || (brr == crr && bcc == ccc)) {
//                brr = br + dirr[i];
//                bcc = bc + dirc[i];
//            }
//            if(grid[cr][cc]!='X') {
            crr = cr + dirr[i];
            ccc = cc + dirc[i];
//            if(crr<0 || crr==n || ccc<0 || ccc==n || grid[crr][ccc]=='#' || (crr ==arr && ccc==acc) || (crr==brr && ccc==bcc) )
//            {
//                crr = cr;
//                ccc = cc;
//            }
            for(int i=0; i<3; i++)
            {

                if(arr<0 || arr==n || acc<0 || acc==n || grid[arr][acc]=='#' || (brr==arr && bcc == acc) || (crr ==arr && ccc==acc))
                {
                    arr = ar;
                    acc = ac;
                }
                if(brr<0 || brr==n || bcc<0 || bcc==n || grid[brr][bcc]=='#' || (brr==arr && bcc == acc) || (crr ==brr && ccc==bcc))
                {
                    brr = br;
                    bcc = bc;
                }
                if(crr<0 || crr==n || ccc<0 || ccc==n || grid[crr][ccc]=='#' || (crr ==arr && ccc==acc) || (crr==brr && ccc==bcc) )
                {
                    crr = cr;
                    ccc = cc;
                }
            }
//            } else if((arr == crr && acc == ccc) || (brr == crr && bcc == ccc)) {
//                crr = cr + dirr[i];
//                ccc = cc + dirc[i];
//            }
            if(arr<0 || arr==n || acc<0 || acc==n || grid[arr][acc]=='#' || brr<0 || brr==n || bcc<0 || bcc==n || grid[brr][bcc]=='#' || crr<0 || crr==n || ccc<0 || ccc==n || grid[crr][ccc]=='#')
                continue;
            else if(vis[arr][acc][brr][bcc][crr][ccc]!=tc)
            {
                Q.push(node(arr, acc, brr, bcc, crr, ccc, cur.cost+1));
                vis[arr][acc][brr][bcc][crr][ccc]=tc;
            }


        }





    }


//    return -1;

}



int main()
{
//    cout<<-13%5;
//    freopen("out.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);

    int t;
    scanf("%d", &t);
    for(tc=1; tc<=t; tc++)
    {
//        memset(grid, 0, sizeof grid);
//        memset(dist1, 0, sizeof dist1);
//        memset(dist2, 0, sizeof dist2);

        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("\n%s", grid[i]);
        }
//        for(int i=0; i<n; i++) {
//            printf("%s\n", &grid[i]);
//        }

        node start;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='A')
                {
                    start.ar = i;
                    start.ac = j;
                }
                else if(grid[i][j]=='B')
                {
                    start.br = i;
                    start.bc = j;
                }
                else if(grid[i][j]=='C')
                {
                    start.cr = i;
                    start.cc = j;
                }
            }
        }
        mn= 1e9;
        bfs(start);
//
////        for(int i=0; i<n; i++)
////            printf("%d ", dist2[i]);
////        printf("\n");
//
        printf("Case %d: ", tc);

        if(mn==1e9)
            printf("trapped\n");
        else
            printf("%d\n", mn);
//        for(int i=0; i<n; i++) {
//            printf("%d\n", max(dist1[i], dist2[i]));
//        }

    }



    return 0;
}
