#include <bits/stdc++.h>
using namespace std;

int frequency[30];
char str[ 100011];
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);
    int n;
    scanf("%d",&n);
    scanf("%s",str);
    if(n>26)
    {
        printf("-1\n");
        return 0;
    }
    int change = 0;
    for(int i=0; i<n; i++)
    {
        frequency[ str[i] - 'a' ]++;
    }
//    for(int i= 0; i<26; i++)
//        printf("%d ",frequency[i]);
//    printf("\n");
    for(int i= 0; i<26; i++)
        if(frequency[i]>0)
            change = change+ frequency[i] -1;
    printf("%d\n",change);

    return 0;
}

