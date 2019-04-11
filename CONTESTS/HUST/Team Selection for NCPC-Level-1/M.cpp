#include <bits/stdc++.h>

using namespace std;
bool isSubstring(char str1[], char str2[])
{
    int len1=strlen(str1);
    for(int i=0;i<len1;i++)
        if(str1[i] != str2[i])
            return false;
    return true;
}
int main()
{
    char previouslyVisited[101], minAddress[101], currentAddress[101];
    int n;
    while(scanf("\n%s %d",previouslyVisited, &n)==2)
    {
        minAddress[0]= '\0';
        //printf("len %d\n",strlen(minAddress));
        while(n--)
        {
            scanf("\n%s",currentAddress);
            if(isSubstring(previouslyVisited,currentAddress))
            {
                if(strlen(minAddress)==0 || strcmp(currentAddress,minAddress)<0)
                    strcpy(minAddress,currentAddress);
            }
        }
        if(strlen(minAddress)==0)
            strcpy(minAddress,previouslyVisited);
        printf("%s\n",minAddress);
    }

    return 0;
}
