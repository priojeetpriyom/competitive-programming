#include <bits/stdc++.h>
using namespace std;
char str[100000];
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w",stdout);


    int i;

    int n;
    scanf("%d",&n);
    str[0] = '0';
    int len=1;
    //printf("oka");
    for(int i=1; i<= n; i++)
    {
        int x= i;
        char temp[100];
        int lenTemp= -1;
        while(x>0)
        {
            temp[++lenTemp] = (x%10);
//            if(x==0)
//                break;
            x/=10;
        }
        for(int j= lenTemp; j>=0; j--)
            str[len++] = temp[j];
    }
    printf("%d\n",str[n]);
    return 0;
}


