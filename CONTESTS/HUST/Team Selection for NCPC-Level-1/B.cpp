#include <bits/stdc++.h>
char gogol[100001], papple[31];
using namespace std;
//bool isSubstring(char str1[], char str2[])
//{
//    int len1=strlen(str1);
//    for(int i=0;i<len1;i++)
//        if(str1[i] != str2[i])
//            return false;
//    return true;
//}
int main()
{
    while(scanf("\n%s \n%s",gogol,papple)==2)
    {
        //printf("%s  %s\n",gogol, papple);
        int lenG=strlen(gogol), lenP= strlen(papple),neededchange=0;
        if(lenG>=lenP)
        {
            int y=0;
            for(int i=0;i<lenG;i++) {

//                if(y>i)
//                    i=y;
                if(gogol[i] == papple[0])
                {
                    int j=1,x=i;
                    if(i+lenP>lenG)
                        break;
//                    if(i==1)
//                    printf("iiiiiiii\n");
                    bool substring=true,jlenP=false;
                    for(j=1;j<lenP;j++)
                    {
                        //jlenP=false;
                        if(gogol[i+j] != papple[j])
                        {
                            substring=false;
                            break;
                        }

                        if(gogol[j]== papple[0] && gogol[j+lenP-1] == papple[lenP-1] && lenP>1)
                            x=j;
//                        if(j== lenP-1)
//                            jlenP=true;
//                        if(gogol[i+j] == papple[0] && x==i)
//                            x=j;
                    }
                    if(substring)
                    {
                        //printf("i %d j %d\n",i,j);
                        //gogol[j]= '#';
                        //if(j-i>1)
                        i=i+j-1;
//                        y=((float)(i+j)/2.0);
//                        if(lenP>1)
//                            y++;
////                        while(gogol[y]== papple[0] && y<i+j)
////                            y++;
//                        if(y== i+j)
//                            y--;
//                        if(y<i)
//                            y=i;
//                        gogol[y]='#';
                        neededchange++;
                    }
                    else if(x!=i)
                        i=x-1;
                    //printf("i %d j %d  ",i,j);
//                    if(jlenP)
                        //
//                    else i= i+j-1;
                    //printf("i %d j %d change %d\n",i,j, neededchange);

                }
//                else
//                printf("baaler code koro tumi\n");
            }
        }
        printf("%d\n",neededchange);

    }

    return 0;
}
