#include <bits/stdc++.h>
using namespace std;
bool isPlaced[9] [9] ={false};
int temp [9],cnt=0;
int ara[20];
bool isValid(int i,int j)
{
    for(int k= i; k< 8 ; k++)
    {
        if(isPlaced[k] [j] == true)
            return false;
    }
    for(int k= i; k>=0; k--)
    {
        if(isPlaced[k] [j] == true)
            return false;
    }
    for(int k= j; k< 8 ; k++)
    {
        if(isPlaced[i] [k] == true)
            return false;
    }
//    for(int i=0; i<8; i++)
//        {
//            for(int j=0; j<8; j++)
//                printf("%d ",isPlaced[i][j]);
//            printf("\n");
//        }
    for(int k= j; k>=0 ; k--)
    {
        //printf(" %d",isPlaced[i][k]);
        if(isPlaced[i] [k] == true)
            return false;
    }

    for(int k= i,l=j; k< 8 && l<8 ; k++,l++)
    {
        if(isPlaced[k] [l] == true)
            return false;
    }
    for(int k= i,l=j; k< 8 && l>=0 ; k++,l--)
    {
        if(isPlaced[k] [l] == true)
            return false;
    }
    for(int k= i,l=j; k>=0 && l>=0 ; k--,l--)
    {
        if(isPlaced[k] [l] == true)
            return false;
    }
    for(int k= i,l=j; k>=0 && l<8 ; k--,l++)
    {
        if(isPlaced[k] [l] == true)
            return false;
    }
    return true;
}
void findPossibleCombinations(int len,int col)
{
//    int x,y;
//    while(scanf("%d %d",&x,&y)==2)
//    {
//        printf("\n%d\n",isValid(x-1,y-1));
//    }
    if(len == 8)
    {
        cnt++;
        printf("%2d     ",cnt);
//        for(int k=0; k< len; k++)
//        {
//            printf(" %d",ara[k]);
////            if(k!=len)
////                printf(" ");
//        }
//        printf("\n");

        for(int k=0; k< len; k++)
        {
            printf(" %d",temp[k]);
//            if(k!=len)
//                printf(" ");
        }
        printf("\n");
        return;
    }



    for(; col<8; col++)
    {
        for(int row=0; row<8; row++)
        {
            if(isValid(row,col))
            {
                //printf("i %d j %d\n",i,j);
                ara[len] = col+1;
                temp[col]= row+1;
                isPlaced[row][col] = true;
                findPossibleCombinations(len+1,col+1);
                isPlaced[row][col] = false;
            }
        }
    }
}
int main()
{
    int x,y,t;
    //freopen("myOutput.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x, &y);
        memset(isPlaced,false,sizeof(isPlaced));
        isPlaced[x-1][y-1] = true;
//        for(int i=0; i<8; i++)
//        {
//            for(int j=0; j<8; j++)
//                printf("%d ",isPlaced[i][j]);
//            printf("\n");
//        }
        temp [y-1] =x;
        ara[0] = x;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        cnt=0;
        findPossibleCombinations(1,0);
        if(t>0)
            printf("\n");
        //break;
        //cout<<cnt;
    }
    return 0;
}

