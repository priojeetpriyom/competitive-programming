#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MX 100100

int change[20] [20], ara[40], temp[40];


void pre()
{

    change[1][1] = 22;
    change[1][2] = 24;
    for(int i=0; i<6; i++)
        change[1][i+3] = i*2+1;
    change[1][9] = 22;
    change[1][10] = 24;
    change[1][11] = 1;
    change[1][12] = 3;


    change[2][1] = 21;
    change[2][2] = 23;
    for(int i=0; i<6; i++)
        change[2][i+3] = i*2+2;
    change[2][9] = 21;
    change[2][10] = 23;
    change[2][11] = 2;
    change[2][12] = 4;


    change[3][1] = 21;
    change[3][2] = 22;
    change[3][3] = 13;
    change[3][4] = 14;
    change[3][5] = 5;
    change[3][6] = 6;
    change[3][7] = 17;
    change[3][8] = 18;

    change[3][9] = 21;
    change[3][10] = 22;
    change[3][11] = 13;
    change[3][12] = 14;

    change[4][1] = 23;
    change[4][2] = 24;
    change[4][3] = 15;
    change[4][4] = 16;
    change[4][5] = 7;
    change[4][6] = 8;
    change[4][7] = 19;
    change[4][8] = 20;

    change[4][9] = 23;
    change[4][10] = 24;
    change[4][11] = 15;
    change[4][12] = 16;

//    for(int i=1; i<=4; i++)
//    {
//        for(int j=1; j<=12; j++)
//            printf("%d ", change[i][j]);
//        printf("\n");
//    }




}


int calc(int r, int offset)
{

//    printf("offset %d\n", offset);


//    for(int i=1; i<=4; i++) {
    for(int j=1; j<=24; j++)
        temp[j] = ara[j];
    for(int j=3; j<=10; j++)
    {
//            if(i==2)
//                printf("i %d j %d change[i,j] %d temp[change[i,j] %d temp[c+o] %d\n", i, j,change[i][j], temp[change[i][j] ], ara[change[i][j + offset] ] );
        temp[ change[r] [j] ] = ara[ change[r] [j+offset]  ];

    }

    int flag=1;
    for(int j=1; j<24; j+=4)
    {
        for(int k = j; k<j+4; k++)
        {
            if(temp[k]!= temp[j])
            {
                flag=0;
                break;
            }
        }
    }
    if(flag)
    {
//            printf("i %d offset %d\n", i, offset);
//            for(int j=1; j<=24; j++)
//                printf("%d ",temp[j]);
//            printf("\n");
        return 1;
    }
//
//    }


    return 0;


}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    std::ios_base::sync_with_stdio(false);
//    cin.tie(0);

    pre();

    for(int i=1; i<=24; i++)
    {
        cin>>ara[i];
    }

    int flag=0;
//    if(!flag)
    for(int i=1; i<=4; i++)
    {

        flag = max(calc(i, 2), calc(i, -2));
        if(flag)
            break;


    }


    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;



    return 0;
}


