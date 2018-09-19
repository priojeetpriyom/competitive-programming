#include <bits/stdc++.h>
using namespace std;
bool isPlaced[10] [10], input[10][10];
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
void findPossibleCombinations(int col,int row,int cnt, int placed)
{
    if(placed== 8){
        mn= min(cnt,mn);
        return;
        }
    if(row==8 || col==8)
        return;
    if(isValid(row,col)) {
//        printf("row %d col %d cnt %d placed %d\n",row+1,col+1,cnt,placed);
        isPlaced[row] [col]=1;
        if(input[row] [col] ==1)
            findPossibleCombinations(col+1,0,cnt,placed+1);
        else
            findPossibleCombinations(col+1,0,cnt+1,placed+1);
        isPlaced[row] [col]=0;
    }
        findPossibleCombinations(col,row+1,cnt,placed);
}
int main()
{
//    freopen("myInput.txt","r", stdin);
//    freopen("myOutput.txt","w", stdout);
    int t=1,x;
    for(t =1; scanf("%d",&x)==1; t++)
    {
        input[x-1] [0]=true;
        //isPlaced[1] [x]=true;
        for(int i=1; i<8; i++)
        {
            scanf("%d",&x);
            input[x-1] [i] =true;
        }
        printf("Case %d: ",t);
        mn= INT_MAX;

//        for(int i=0; i<8; i++) {
//            for(int j=0; j<8; j++)
//                printf("%d ", input[i][j]);
//            printf("\n");
//        }

        findPossibleCombinations(0,0,0,0);
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
