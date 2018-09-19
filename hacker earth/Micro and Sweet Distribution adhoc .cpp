#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
//        freopen("out.txt", "w", stdout);


    int n, m;
    int t;
    cin>>t;
    int sr,sc,dr,dc;

    while(t--)
    {
        scanf("%d %d", &n, &m);
        scanf("%d %d %d %d", &sr, &sc, &dr, &dc);

        if(sr==1 && sc ==1)
        {
            if((dr-sr+1)%2==1)
            {
                if(dr == n && dc==m)
                    printf("Over\n");
                else if(dc == m)
                {
                    printf("Back\n");
                }
                else
                    printf("Right\n");
            }
            else
            {
                if(dr == n && dc==1)
                    printf("Over\n");
                else if(dc == 1)
                {
                    printf("Back\n");
                }
                else
                    printf("Left\n");
            }

        }
        else if(sr==1 && sc ==m)
        {
            if((dr-sr+1)%2==0)
            {
                if(dr == n && dc==m)
                    printf("Over\n");
                else if(dc == m)
                {
                    printf("Back\n");
                }
                else
                    printf("Right\n");
            }
            else
            {
                if(dr == n && dc==1)
                    printf("Over\n");
                else if(dc == 1)
                {
                    printf("Back\n");
                }
                else
                    printf("Left\n");
            }
        }
        else if(sr==n && sc ==1)
        {
            if((sr - dr +1)%2==1)
            {
                if(dr == 1 && dc==m)
                    printf("Over\n");
                else if(dc == m)
                {
                    printf("Front\n");
                }
                else
                    printf("Right\n");
            }
            else
            {
                if(dr == 1 && dc==1)
                    printf("Over\n");
                else if(dc == 1)
                {
                    printf("Front\n");
                }
                else
                    printf("Left\n");
            }
        }
        else if(sr==n && sc ==m)
        {

            if((sr- dr+1) %2==0)
            {
                if(dr == 1 && dc==m)
                    printf("Over\n");
                else if(dc == m)
                {
                    printf("Front\n");
                }
                else
                    printf("Right\n");
            }
            else
            {
                if(dr == 1 && dc==1)
                    printf("Over\n");
                else if(dc == 1)
                {
                    printf("Front\n");
                }
                else
                    printf("Left\n");
            }
        }


    }

    return 0;
}


