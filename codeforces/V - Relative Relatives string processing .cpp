#include <bits/stdc++.h>
using namespace std;
struct node{
    char parent[101], child[101];
    int finalAge=0,initialAge=0;
};
int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n;int j;
        scanf("%d",&n);
        struct node araNode[101];

        int start= -1;
//        strcpy(araNode[0].parent,"Ted");
//        araNode[0].finalAge=100;
        for(int i=0; i<n; i++)
        {
            scanf("\n%s \n%s %d",araNode[i].parent, araNode[i].child, &araNode[i].initialAge);

            if(strcmp("Ted",araNode[i].parent)==0)
                {
                    //printf("parent %s\n",araNode[0].parent);
//                    araNode[i].finalAge= 100;
                    if(start == -1)
                        start=i;
                }
//            for(j=0; j<i; j++)
//            {
//                if(strcmp(araNode[i].child,araNode[j].parent))
//            }
        }
        //printf("%s\n",araNode[0].parent);
        for(int i=0; i<n; i++)
        {


            if(strcmp("Ted",araNode[i].parent)==0)
            {
                printf("start %d j %d\n",start,j);
                araNode[i].finalAge= 100- araNode[i].initialAge;
                //start=i;a
                int araDes[100],len=0;
                for(j=0; j<n; j++)
                    {
                        if(strcmp(araNode[j].parent,araNode[i].child)==0)
                        {
                            araDes[len++]=j;
                        }
                    }
                printf("initial %d final %d\n",araNode[0].initialAge,araNode[0].finalAge);

                for(int k =0; k<len; k++)
                {
                    start=araDes[k];
                    printf("oka\n");
                    //getchar();
                    for(j=0; j<n; j++)
                    {
                        if(strcmp(araNode[j].parent,araNode[start].child)==0)
                        {
                            printf("start %d j %d\n",start,j);
                            araNode[j].finalAge= araNode[start].finalAge- araNode[j].initialAge;
                            start=j;
                            break;
                        }
                    }
                    if(j==n)
                        break;
                }
            }
        }
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(araNode[i].finalAge < araNode[j].finalAge)
                {
                    swap(araNode[i],araNode[j]);
                }
                else if(araNode[i].finalAge == araNode[j].finalAge)
                    if(strcmp(araNode[i].child,araNode[j].child) >0)
                        swap(araNode[i],araNode[j]);
            }
        }
        for(int i=0; i<n; i++)
            printf("%s %d\n",araNode[i].child, araNode[i].finalAge);
    }
    return 0;
}

