#include <iostream>
#include <cstdio>
using namespace std;
int main ()
{
    int t,r=3,c=0,i,row,col,coun;
    scanf("%d",&t);
    for (i=0; i<t; i++) {
        coun=0;
        r=3,c=0;
        scanf("%d %d",&row,&col);
        //int ara [row] [col];
        if (row>5 && col>5) {
        while (1) {
            if (c+3 < col) {
                c=c+3;
                coun++;
            }
            else if (c+2<col) {
                c=c+2;
                coun++;
            }
            else {
                if (r+3 <row) {
                r=r+3;
                c=0;
                }
                else if (r+2 < row ) {
                r=r+2;
                c=0;
                }
                else {
                    printf("%d\n",coun);
                    break;
                }
            }
        }

        }
        else printf("1\n");
    }
    return 0;
}
