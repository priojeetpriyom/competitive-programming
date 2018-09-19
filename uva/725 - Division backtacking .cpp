#include <bits/stdc++.h>

using namespace std;
char str[20], str2[20];
int n,lenStr2;
bool notPicked[20],noSolution;
void intToChar(int n)
{
    lenStr2=0;
    while(n>0)
    {
        str2[lenStr2++] = n%10 + '0';
        n/=10;
    }
    str2[lenStr2] = '\0';
    for(int i=0; i<lenStr2/2; i++)
        swap(str2[i], str2[lenStr2-i-1]);
    //printf("%s\n",str2);
}
bool isDistinct(char temp [])
{
    bool check [60] = {false};
    for(int i=0; i<5; i++)
        {
            if(check[temp[i]] == false)
                check[temp[i]]=true;
            else
                return false;
        }
    for(int i=0; i<lenStr2; i++)
        {
            if(check[str2[i]] == false)
                check[str2[i]]=true;
            else
                return false;
        }
    return true;
}
bool isZeroAvailable(char temp[])
{
    //bool check [60] = {false};
    for(int i=0; i<5; i++)
        {
            if(temp[i] == '0')

                return false;
        }
    for(int i=0; i<lenStr2; i++)
        {
            if(str2[i] == '0')
                return false;
        }
    return true;
}
void permute(char temp[], int i, int len)
{
    if(len==5)
    {
        temp[len]='\0';
        int x = atoi(temp);
        //printf("%s  %d\n",temp,x);
        if(x%n ==0 && x/n >=1000)
            {
                intToChar(x/n);
                if(isDistinct(temp))
                {
                    if(x/n>9999)
                    {
                        printf("%d / %d = %d\n",x,x/n,n);
                        noSolution=false;
                    }
                    else if(isZeroAvailable(temp))
                        {
                            printf("%d / 0%d = %d\n",x,x/n,n);
                            noSolution=false;
                        }
                }
            }
        return;
    }
////    else if(len==4)
////    {
////        temp[len]='\0';
////        int x = atoi(temp);
////        if(x%n ==0 && x/n >=1000)
////            printf("%d / %d = %d\n",x,x/n,n);
////        //return;
////    }
    if(i==10)
        return;
    for(int j=0; j<10; j++)
    {
        if(notPicked[j])
        {
            temp[len] = str[j];
            notPicked[j] = false;
            permute(temp, i+1, len+1);
            notPicked[j] = true;
//            permute(temp, i+1, len);
        }
    }


}

int main()
{
   //freopen("myOutput.txt", "w", stdout);
   char temp[10];
   bool first=true;
   while(scanf("%d",&n)==1 && n!=0)
   {
       if(first)
            first=false;
       else
        printf("\n");
       memset(notPicked, 1, sizeof(notPicked));
       for(int i=0; i<10; i++)
            str[i]= i+'0';
        str[10] = '\0';
        //printf("%s\n",str);
//        intToChar(123);
//        printf("%s\n",str2);
//       do
//       {
            noSolution=true;
           permute(temp, 0, 0 );
//       } while(next_permutation(str,str+10));
        if(noSolution)
            printf("There are no solutions for %d.\n",n);
   }

   //getchar();
   return 0;
}
