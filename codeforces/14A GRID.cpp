#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[60] [60];
    int row,col,startRow,endRow,startCol,endCol;
    while(scanf("%d %d",&row,&col)==2)
    {
        startRow= -1,endRow= -1,startCol= -1,endCol= -1;
        for(int i=0;i<row;i++)
            scanf("\n%s",str[i]);
//        printf("\n\n\n");
//        for(int i=0;i<row;i++)
//        printf("%s\n",str[i]);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(str[i] [j]== '*')
                {
                    //printf("i %d j %d\n",i,j);
                    if(startRow== -1)
                        startRow=i;

                    endRow=i;

                    if(startCol== -1 || j<startCol)
                        startCol=j;
//                    else if()
//                        startCol=j;
                    if(endCol== -1 || j>endCol)
                        endCol=j;
                }
            }

        }
        //printf("scol %d ecol %d\n",startCol,endCol);
        if(startCol==0 && endCol== -1)
        {
            endCol=0;
            //cout<<"hrer "<<endCol<<endl;
        }
        if(startRow== 0 && endRow== -1)
            endRow=0;

        //printf("%d %d %d %d\n",startRow,startCol,endRow,endCol);
        for(int i =startRow;i<=endRow;i++)
        {
            for(int j=startCol;j<=endCol;j++)
            {
                printf("%c",str[i] [j]);
            }
            printf("\n");
        }
    }
    return 0;
}
