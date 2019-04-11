
#include <bits/stdc++.h>
using namespace std;

char str[10] [10];


int main()
{
//    freopen("myOut.txt", "w", stdout);

    int n=4;
    for(int i=0; i<n; i++)
        scanf("\n%s", str[i]);
    int cnt=0, used=0;

//    for(int i=0; i<n; i++)
//        printf("%s\n", str[i]);

    for(int i=0; i<n; i++)
    {
        for(int j =0; j<n; j++)
        {
            cnt=0;
            used=0;
//            printf("i %d j %d\n", i,j);
            for(int p = i; p<i+3 && p<n; p++)
            {
                if(str[p][j] == 'x')
                {
                    cnt++;
                }
                if( ( str[p] [j] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }

            cnt=0;
            used=0;
            for(int p = j; p<j+3 && p<n; p++)
            {
                if(str[i][p] == 'x' )
                {
                    cnt++;
                }
                if(( str[i] [p] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
//                printf("p %d cnt %d used %d\n", p, cnt, used);
            }
//            printf("cnt %d used %d\n", cnt, used);
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }


            cnt=0;
            used=0;
            for(int p = i; p>i-3 && p>=0; p--)
            {
                if(str[p][j] == 'x' )
                {
                    cnt++;
                }
                if(( str[p] [j] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }


            cnt=0;
            used=0;
            for(int p = j; p>j-3 && p>=0; p--)
            {
                if(str[i][p] == 'x' )
                {
                    cnt++;
                }
                if( ( str[i] [p] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }



            cnt=0;
            used=0;
            for(int p = i, q =j; p>i-3 && p>=0 && q>=0; p--, q--)
            {
                if(str[p][q] == 'x')
                {
                    cnt++;
                }
                if( ( str[p] [q] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }


            cnt=0;
            used=0;
            for(int p = i, q =j; p<i+3 && p<n && q>=0; p++, q--)
            {
                if(str[p][q] == 'x')
                {
                    cnt++;
                }
                if( ( str[p] [q] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }

            cnt=0;
            used=0;
            for(int p = i, q =j; p<i+3 && p<n && q<n; p++, q++)
            {
                if(str[p][q] == 'x' )
                {
                    cnt++;
                }
                if(( str[p] [q] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }


            cnt=0;
            used=0;
            for(int p = i, q =j; p>i-3 && p>=0 && q<n; p--, q++)
            {
                if(str[p][q] == 'x' )
                {
                    cnt++;
                }
                if( ( str[p] [q] == '.' && used ==0))
                {
                    cnt++;
                    used=1;
                }
            }
            if(cnt==3)
            {
                printf("YES\n");
                return 0;
            }




        }
    }
    printf("NO\n");
    return 0;
}
