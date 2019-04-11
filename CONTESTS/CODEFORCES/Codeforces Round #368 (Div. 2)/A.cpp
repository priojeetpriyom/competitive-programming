#include <bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("myOutput.txt","w",stdout);

    char str[111] [111];
    int row,col;
    while(scanf("%d %d",&row,&col)==2) {
        getchar();

        for(int i=0; i<row; i++)
        {
            gets(str[i]);
//            printf("%s\n\n",str[i]);
        }
        bool color= false;
        for(int i=0; i<row; i++){
            for(int j=0; j<col*2; j++) {
                if(str[i][j] == 'C' || str[i][j] == 'M' || str[i][j] == 'Y')
                {
                    color =true;
                    break;
                }

            }

        }
        if(color)
            printf("#Color\n");
        else
            printf("#Black&White\n");
    }
    return 0;
}
