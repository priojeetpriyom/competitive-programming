#include <bits/stdc++.h>

using namespace std;

long long male[100011],female[100011],children[100011];
int main()
{

    int tCase;
    scanf("%d",&tCase);
    for(int j=0;j<tCase;j++)
    {
        if(j>0)
            printf("\n");
        int n;
        scanf("%d",&n);
        long long temp;
        male[0]=0,female[0]=0,children[0]=0;
        for(int i=1;i<=n;i++)
        {

                scanf("%lld",&temp);
                male[i]= temp+male[i-1];
                scanf("%lld",&temp);
                female[i]=temp+ female[i-1];
                scanf("%lld",&temp);
                children[i]=temp+ children[i-1];

        }



        int querry;
        scanf("%d",&querry);

        for(int i=0;i<querry;i++)
        {

            long long a,b;
            char c;

            scanf("%lld",&a);

            //getchar();
            scanf("\n%c",&c);
            scanf("%lld",&b);
            //printf("a %lld b %lld\n",a,b);

            if(a==b)
                printf("%lld %lld %lld\n",male[b]-male[b-1],female[b]-female[b-1],children[b]-children[b-1]);
            else
                {
                    if(a>b)
                        swap(a,b);
                    printf("%lld %lld %lld\n",male[b] - male[a-1],female[b] - female[a-1],children[b] - children[a-1]);
                }
        }
    }
    return 0;
}
