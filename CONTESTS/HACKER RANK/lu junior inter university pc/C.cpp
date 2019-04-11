#include <bits/stdc++.h>

using namespace std;

int main()
{
    char kobiraj[1001],nodiraj[1001];
    while(scanf("%s %s",kobiraj,nodiraj)==2)
    {
        if(strcmp(kobiraj,"JIUPC")==0)
            break;
            int len =strlen(kobiraj);
        for(int i=0;i<len;i++)
            kobiraj[i]= toupper(kobiraj[i]);
        len =strlen(nodiraj);
        for(int i=0;i<len;i++)
            nodiraj[i]= toupper(nodiraj[i]);
        if(strcmp(kobiraj,nodiraj)>0)
            printf("Nodiraj Has Gone\n");
        else if(strcmp(kobiraj,nodiraj)<0)
            printf("Kobiraj Has Gone\n");
        else
            printf("Uh ho\n");
    }
}
