#include <bits/stdc++.h>
using namespace std;
char str[200010];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
//    while(1) {
    int len,t;
    scanf("%d %d",&len, &t);

    scanf("\n%s",str);
    int pos=0;
    for(int cnt=0; cnt<t&& pos<len; pos++)
    {
        if(str[pos]== '.')
        {
            for(int i=pos; i<len-1; i++ )
                str[i]=str[i+1];
            break;
        }
    }


    len--;
    str[len] = '\0';

    bool oka=true;
    while(oka)
    {
        if(str[pos]>='5') {
            len = pos;
            int j = pos-1;
                    while(str[j]=='9')
                    {
                        str[j]='0';
                        if(j==0)
                        {
//                            printf("aise");
//                            printf("before %s i %d len %d\n",str,i,len);
                            len++;
                            pos++;

                            for(int k=len-1; k>0; k--)
                                str[k] = str[k-1];
                            str[0]= '0';
                            str[len] ='\0';

//                            printf("after %s i %d len %d\n",str,i,len);
                            break;
                        }
                        else j--;
                    }

                    str[j] = str[j]+1;
                    break;
        }
        oka=false;
        for(int i=pos; i<len && t>0; i++)
        {
//        printf("%s\n",str);
//            while(str[i]=='9' && str[i+1]>='5')
//                i++;
            if(str[i]>= '5')
            {
                oka =true;
//                str[i]='0';
                t--;
                int cary=1;
                int j = i-1;
                    while(str[j]=='9')
                    {
                        str[j]='0';
                        if(j==0)
                        {
//                            printf("aise");
//                            printf("before %s i %d len %d\n",str,i,len);
                            len++;
                            pos++;
                            i++;
                            for(int k=len-1; k>0; k--)
                                str[k] = str[k-1];
                            str[0]= '0';
                            str[len] ='\0';

//                            printf("after %s i %d len %d\n",str,i,len);
                            break;
                        }
                        else j--;
                    }

                str[j] = str[j]+1;
                len=i;
//                printf("last %s i %d\n",str,i);
            }

        }
    }
//    printf("%s pos %d len %d\n",str,pos, len);
    int x;
    for (x= len-1; x>=pos && str[x]=='0'; x--);


    for(int i=0; i<= x; i++)
    {
        if(i==pos)
            printf(".");
        printf("%c",str[i]);
    }
    printf("\n");
//    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char str[200010];
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
//    while(1) {
    int len,t;
    scanf("%d %d",&len, &t);

    scanf("\n%s",str);
    int pos=0;
    for(; pos<len; pos++)
    {
        if(str[pos]== '.')
        {
            for(int i=pos; i<len-1; i++ )
                str[i]=str[i+1];
            break;
        }

    }
        int start;




        len--;
        str[len] = '\0';

        for(start =pos; start<len; start++)
            if(str[start]>='5')
            {
                break;
            }
//        printf("len %d\n",len);
        if(start!=len)
        for(int i=start; i>=pos && t>0; i--)
        {
//        printf("%s\n",str);
//            while(str[i]=='9' && str[i+1]>='5')
//                i++;
            if(str[i]>='5') {
                t--;
                int j = i-1;

                while(str[j]=='9')
                {
                    str[j]='0';
                    if(j==0)
                    {
//                            printf("aise");
//                            printf("before %s i %d len %d\n",str,i,len);
                        len++;
                        pos++;
                        i++;
                        for(int k=len-1; k>0; k--)
                            str[k] = str[k-1];
                        str[0]= '0';
                        str[len] ='\0';

//                            printf("after %s i %d len %d\n",str,i,len);
                        break;
                    }
                    else j--;
                }

                str[j] = str[j]+1;
                len=i;
            } else {
                break;
            }

        }
//
//    printf("%s pos %d len %d\n",str,pos, len);
    int x;
    for (x= len-1; x>=pos && str[x]=='0'; x--);


    for(int i=0; i<= x; i++)
    {
        if(i==pos)
            printf(".");
        printf("%c",str[i]);
    }
    printf("\n");
//    }

    return 0;
}
