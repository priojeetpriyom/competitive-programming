#include <bits/stdc++.h>
using namespace std;
bool verdict;
int ara[6];
int temp[6];
char sign[10];

int main()
{
    //freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    int t, n,h;
    char str[20];
    scanf("%d",&t);
    for(int i=0; i<t; i++)
    {
        scanf("%d %d",&n, &h);
        int j;
        for(j=0; j<n-h; j++)
            str[j]= '0';
        for(j= n-h; j<n; j++)
            str[j]='1';
        str[j] = '\0';
        do
        {
            printf("%s\n",str);
        }
        while(next_permutation(str,str+n));
        if(i!= t-1)
            printf("\n");
    }
    return 0;
}

