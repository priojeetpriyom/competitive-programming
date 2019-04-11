#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#define MEM(a,b) memset((a),(b),sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define In freopen("In.txt", "r", stdin);
#define Out freopen("out.txt", "w", stdout);

using namespace std;

int main()
{
    int t,x,y;
    char ch;
    int i,j,l;
    scanf("%d",&t);
    char tmpstr[1100];
    char str[1000][1000];
    while(t--)
    {
        MEM(str,0);
        scanf("%d %d %c",&x,&y,&ch);
        getchar();
        for(i=0; i<x; i++)
        {
            MEM(tmpstr,0);
//            gets(tmpstr);
//            tmpstr[strlen(tmpstr)]= '\0';
//            for(j=0; j<y; j++)
//            {
//                str[i][j] = tmpstr[j];
//            }
            //str[i][j] = '\0';
            scanf("%s",str[i]);
        }
        if(ch=='L')
        {
            for(j=y-1; j>=0; j--)
            {
                for(i=0; i<x; i++)
                {
                    printf("%c",str[i][j]);
                }
                printf("\n");
            }
        }
        else if(ch=='R')
        {
            for(j=0; j<y; j++)
            {
                for(i=x-1; i>=0; i--)
                {
                    printf("%c",str[i][j]);
                }
                printf("\n");
            }

//printf("\n\n\n");


//            for(j=0; j<y; j++)
//            {
//                for(i=x-1; i>=0; i--)
//                {
//                    printf("%c",str[j][i]);
//                }
//                printf("\n");
//            }
        }
        else if(ch=='F')
        {
            for(i=0; i<x; i++)
            {
                for(j=y-1; j>=0; j--)
                {
                    printf("%c",str[i][j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}

/*


1
4 4 R
X##X
XX##
X#X#
XXXX


XXXX
X#X#
XX##
X##X
X##X
##XX
#X#X
XXXX


*/
