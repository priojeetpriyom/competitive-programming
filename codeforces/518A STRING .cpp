#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[111],t[111];
    bool ok=false;
    //int lexi=0;
    while(scanf("\n%s \n%s",s,t)==2)
    {
        //lexi=0;
        ok=false;
        //bool confusion=false;
        int len = strlen(s);
        s[len]= '\0';
        t[len]= '\0';
        for(int i=0; i<len; i++)
        {
//            if(t[i]-s[i]>1)
//                break;
            if(t[i]-s[i]>1)
            {
                //confusion=true;
                ok=true;
                break;
            }
            else if(t[i]-s[i]==1)
            {
                //lexi++;
                if(i!= len-1)
                {
                    for(i=i+1; i<len; i++)
                        if(s[i]!='z' || t[i] != 'a')
                        {
                            ok=true;
                            break;
                        }
                    break;
                    //break;
                }
            }
//            else
//                break;
//            else if(confusion)
//            {
//                //confusion=;
//                ok=true;
//                break;
//            }
            //else confusion=false;


        }
        //printf("lexi %d\n",lexi);
        if(!ok)
            printf("No such string\n");
        else
        {
//            if(lexi>1)
//            {
            int i=len-1;
                for(; i>=0; i--)
                {
                    if(s[i]!='z')
                    {
                        //printf("%c",s[i]+1);
                        s[i]=s[i]+1;
                        //i++;
                        break;
                    }
                    else
                        s[i]= 'a';
                }
////                    else
////                        printf("%c",s[i]);
//                }
            //s[i]=s[i]+1;
            //for(; i>=0; i)
            printf("%s",s);
            printf("\n");
//            }
//            else
//            {
//                int i=0;
//                for(; i<len; i++)
//                {
//                    if(t[i]-s[i]>1)
//                    {
//                        printf("%c",s[i]+1);
//                        i++;
//                        break;
//                    }
//                    else
//                        printf("%c",s[i]);
//                }
//                for(; i<len; i++)
//                    printf("%c",s[i]);
//                printf("\n");
//            }
        }
    }
    return 0;
}
