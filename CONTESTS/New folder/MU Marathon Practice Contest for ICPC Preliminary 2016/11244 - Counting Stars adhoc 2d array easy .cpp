#include <bits/stdc++.h>
using namespace std;

char str[111] [111];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);


    int row,col;

    while(scanf("%d %d",&row, &col)==2 && row!=0) {
        memset(str,0,sizeof(str));
        for(int r=0; r<row; r++)
            scanf("\n%s",str[r]);
        int stars=0;
        int dr[] ={-1, -1, -1,0,1,1,1,0};
        int dc[] ={-1, 0, 1, 1, 1, 0, -1, -1};
        for(int r=0; r<row; r++) {
            for(int c=0; c<col; c++) {
                if(str[r][c] == '*') {
                    bool cnt = true;
                for(int i=0; i<8; i++) {
                    if(str[r +dr[i] ] [c+ dc[i] ] == '*')
                    {
                        cnt =false;
                        break;
                    }
                }
                if(cnt)
                    stars++;
                }
            }
        }
        printf("%d\n",stars);
    }

    return 0;
}

