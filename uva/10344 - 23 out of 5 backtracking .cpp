#include <bits/stdc++.h>
using namespace std;
bool verdict;
int ara[6];
int temp[6];
char sign[10];
void isPossible(int sum,int nums)
{

//    for(int j=0;j<lenTemp;j++)
//                printf("%d ",temp[j]);
//            printf("\n");
    //printf("sum %d num %d  %s\n",sum,nums,sign);
    if(nums==5)
    {
        if(sum==23)
        {
            verdict= true;
            //printf("uprer tar lagi\n");
        }
        return;
    }
    else if(nums == 0)
    {
        isPossible(ara[nums], nums+1);
        isPossible(ara[nums], nums+1);
        isPossible(ara[nums], nums+1);
    }
    else
    {
//        sign[nums] = '+';
        isPossible(sum+ara[nums], nums+1);
//        sign[nums] = '\0';
        //swap(ara[nums],ara[nums+1]);
        //isPossible(sum, nums+1, lenTemp+1,notPicked);
        //swap(ara[nums],ara[nums+1]);
//        sign[nums] = '-';
        isPossible(sum-ara[nums], nums+1);
////    swap(ara[nums],ara[nums+1]);
////    isPossible(sum, nums+1, lenTemp+1,notPicked);
//        //swap(ara[nums],ara[nums+1]);
////        if(sum==0 && nums == 0)
////            sum=1;
//        sign[nums] = '*';
        isPossible(sum*ara[nums], nums+1);
//        sign[nums] = '\0';
    }

//    swap(ara[nums],ara[nums+1]);
//    isPossible(sum, nums+1, lenTemp+1,notPicked);
    //swap(ara[nums],ara[nums+1]);
//    for(int i=0; i<5; i++)
//    {
//        //printf("%d %d\n",i,sum);
//        if(notPicked[i])
//        {
//            notPicked[i]=false;
//            temp[lenTemp]= ara[i];
//            sign[lenTemp]='+';
//            isPossible(sum+ara[i], nums+1, lenTemp+1,notPicked);
//            //notPicked[i]=false;
//            notPicked[i]=false;
//            //isPossible(sum, i+1);
//            sign[lenTemp]='\0';
//            sign[lenTemp]='-';
//            isPossible(sum-ara[i], nums+1, lenTemp+1,notPicked);
//            notPicked[i]=false;
//            //notPicked[i]=true;
////            if(sum==0)
//////                isPossible(ara[i], nums+1);
////            else
//            sign[lenTemp]='\0';
//            sign[lenTemp]='*';
//            isPossible(sum*ara[i], nums+1, lenTemp+1,notPicked);
//            //isPossible(sum, i+1);
//            sign[lenTemp]='\0';
//            //notPicked[i]=false;
//            notPicked[i]=true;
//        }
//    }
}
int main()
{
    //freopen("myOutput.txt","w",stdout);
    //freopen("myInput.txt",")
    while(1)
    {
        bool notPicked[6];
        scanf("%d %d %d %d %d",&ara[0], &ara[1], &ara[2], &ara[3], &ara[4]);
        if(ara[0]==0 && ara[1] ==0 && ara[2] ==0 && ara[3] ==0 && ara[4] ==0)
            break;
        verdict=false;
        memset(notPicked, true, sizeof(notPicked));
//        isPossible(0,0);
        sort(ara, ara+5);
        do
        {
//            for(int i=0; i<5; i++)
//                printf("%d ",ara[i]);
//            printf("\n");
//            printf("function called\n");
            isPossible(0,0);
            if(verdict)
                break;
        }
        while(next_permutation(ara,ara+5));
        if(verdict)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}

