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
    int n,s,mx=0,f;
    while(scanf("%d %d",&n, &s)==2) {
        int ara[102];
        for(int i=0;i<102;i++)
            ara[i]=0;
        while(n--)
        {
            scanf("%d %d",&f, &mx);
            ara[f]= mx;
        }
        mx=0;
        int downsteps=0;
        for(int i= s; i>=0;i--)
        {

//            if(ara[i]>0)
//            {
//                if(mx<ara[i])
//                {
//                    mx=ara[i];
//                    //downsteps=0;
//                }
//                else
//                    mx+=1;
                mx = max(mx+1,ara[i]);
            //}
//            //else mx++;
//            if(i>0)
//            downsteps++;
        }
        //mx+=downsteps;
        printf("%d\n",mx);
    }


    return 0;
}
