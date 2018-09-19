#include <bits/stdc++.h>
using namespace std;
bool isPlaced[9] [9], input[9][9];
int ara[20],mn;
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
void findPossibleCombinations(int len,int row,int cnt)
{
//    int x,y;
//    while(scanf("%d %d",&x,&y)==2)
//    {
//        printf("\n%d\n",isValid(x-1,y-1));
//    }
    //printf("cnt %d len %d row %d col %d\n",cnt, len, sumRow, sumCol);
    if(len == 8)
    {
        //printf("oka");
        if(cnt<mn)
            mn=cnt;
       // printf("%2d     ",cnt);
//        for(int k=0; k< len; k++)
//        {
//            printf(" %d",ara[k]);
////            if(k!=len)
////                printf(" ");
//        }
//        printf("\n");

//        for(int k=0; k< len; k++)
//        {
//            printf(" %d",temp[k]);
////            if(k!=len)
////                printf(" ");
//        }
//        printf("\n");
        return;
    }
    int col;
    for(col=1; col<=8; col++)
        if(input[row] [col])
            break;
//    if(isValid(row,col))
//    {
//        isPlaced[row] [col] = true;
//        findPossibleCombinations(len+1,row+1,cnt, sumRow+row,sumCol+col);
//        isPlaced[row] [col] = false;
//    }
//
//    else
    {
        for(; row<9; row++)
    {
        for(col=1; col<9; col++)
        {
            if(isValid(row,col))
            {
                //printf("i %d j %d\n",i,j);
//                ara[len] = col+1;
//                temp[col]= row+1;
                isPlaced[row][col] = true;
                if(input[row] [col] == true)
                    findPossibleCombinations(len+1,row+1,cnt);

                else
                    findPossibleCombinations(len+1,row+1, cnt+1);
                isPlaced[row][col] = false;
            }
        }
    }
    }
}
int main()
{
    int t=1,x;
    for(t =1; scanf("%d",&x)==1; t++)
    {
        input[1] [x]=true;
        //isPlaced[1] [x]=true;
        for(int i=2; i<9; i++)
        {
            scanf("%d",&x);
            input[i] [x] =true;
        }
        printf("Case %d: ",t);
        mn= INT_MAX;
        findPossibleCombinations(0,1,0);
        printf("%d\n",mn);
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
            {
                isPlaced[i] [j] = false;
                input[i] [j] = false;
            }
//        for(int i=1; i<9; i++)
//            if(isPlaced)
    }
    return 0;
}
