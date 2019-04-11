#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    char premik [51] [31], premika[51] [31];
    int tCase;
    scanf("%d", &tCase);
    while(tCase--) {
        scanf("%d", &n);
        for(int i=0;i<n; i++)
        {
            scanf("\n%s \n%s",premik[i], premika[i]);
        }
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int i;
            char temp[31];
            scanf("\n%s",temp);
            for(i=0;i<n;i++)
            {
                if(strcmp(temp,premik[i])==0)
                {
                    printf("%s\n",premika[i]);
                    i= -1;
                    break;
                }
            }
            if(i!= -1)
                printf("Unknown Song\n");
        }
        //printf("%lld\n",min(abs(clockWise),180-abs(clockWise)));
    //}
    }
    return 0;
}
