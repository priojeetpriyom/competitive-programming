#include <bits/stdc++.h>
using namespace std;

int ara[505][505];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    int n,position_row,position_col;
    scanf("%d",&n);

    for(int i=0; i<n;i++) {
        for(int j=0; j<n; j++) {
            scanf("%d",&ara[i][j]);
            if(ara[i][j]==0){
                position_col=j;
                position_row= i;
            }
        }
    }
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    int row = position_row+1;
    if(row == n)
        row-=2;
    int sum_row=0,sum_magic=0;

    for(int j=0; j<n; j++)
        sum_row+=ara[row][j];

    for(int j=0; j<n; j++)
        sum_magic+=ara[position_row] [j];

    if(sum_row<=sum_magic) {
        printf("-1\n");
        return 0;
    }
    ara[position_row] [position_col] = sum_row - sum_magic;

    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=0; j<n; j++) {
            sum+= ara[i][j];
        }
        if(sum!= sum_row)
        {
            printf("-1\n");
            return 0;
        }
    }

    for(int j=0; j<n; j++) {
        int sum=0;
        for(int i=0; i<n; i++) {
            sum+= ara[i][j];
        }
        if(sum!= sum_row)
        {
            printf("-1\n");
            return 0;
        }
    }


    int sum=0;
    for(int i=0; i<n;i++) {

            sum+= ara[i][i];
        }
    if(sum!=sum_row)
    {
        printf("-1\n");
            return 0;
    }
    sum=0;
    for(int i=0; i<n; i++) {
        sum+= ara[i] [n-i-1];
    }

    if(sum!=sum_row)
    {
        printf("-1\n");
            return 0;
    }
    printf("%d\n",sum_row-sum_magic);

    return 0;
}
