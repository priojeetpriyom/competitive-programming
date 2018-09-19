#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",") ;;;we
    int t;
    scanf("%d",&t);
    int deadline[1001], reducedMarks[1001],n, generated[1001];
    while(t--)
    {
        scanf("%d",&n);
        memset(generated,0,sizeof(generated));
//        for(int i=0; i<1001; i++)
//            printf("%d ",generated[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&deadline[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&reducedMarks[i]);
        for(int i=0; i<n; i++)
        {
            for(int j= i+1; j<n; j++)
            {
                if(reducedMarks[j] > reducedMarks[i])
                {
                    swap(reducedMarks[j], reducedMarks[i]);
                    swap(deadline[i], deadline[j]);
                }
                else if(reducedMarks[j] == reducedMarks[i] && deadline[i]> deadline[j])
                {
                    swap(reducedMarks[j], reducedMarks[i]);
                    swap(deadline[i], deadline[j]);
                }
            }
        }

//        int cnt=0;
//        for(int i=0; i<n; i++)
//        {
//            if(cnt<deadline[i])
//            {
//                cnt++;
//                reducedMarks[i]=0;
//            }
//        }
//        cnt=0;
//        for(int i=0; i<n; i++)
//            cnt+=reducedMarks[i];

        for(int i=0; i<n; i++)
        {
            for(int j = deadline[i]; j>=1; j--)
            {
                if(reducedMarks[i]>generated[j])
                {
                    generated[j]= reducedMarks[i];
                    break;
                }
            }
        }
        int SUM=0,sum=0;
        for(int i=0; i<n; i++)
            SUM+=reducedMarks[i];
        for(int i=0; i<1001; i++)
            sum+=generated[i];
        printf("%d\n",SUM-sum);
    }

    return 0;
}


