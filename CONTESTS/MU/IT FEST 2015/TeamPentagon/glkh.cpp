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
    int n,t;
    char line1[100], line2[100];
    scanf("%d",&t);
    getchar();
    for(int i=1; i<=t; i++)
    {
        scanf("%s %s",line1,line2);
        int len1 = strlen(line1);
        int len2 = strlen(line2);
        if(len1<len2)
        {
            printf("0\n");
        }
        else if(strcmp(line1,line2)==0)
        {
            printf("1\n");
        }
        else
        {
            int l = 0;
            for(int j=0; j<len1; j++)
            {
                if(line1[j] == line2[l])
                {
                    l++;
                }
            }
            if(l == len2)
            {
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }
    return 0;


}

