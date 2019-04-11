#include <bits/stdc++.h>
using namespace std;

char str[30];
int main()
{
//    freopen("myOutput.txt","w",stdout);

    int tcase;
    scanf("%d",&tcase);

    for(int t=1; t<=tcase; t++) {

        char ans[100];
        memset(ans,0,sizeof(ans));
        scanf("\n%s",str);
        printf("Case %d: ",t);
        int len = strlen(str);
        char temp[10],len_temp=0;
        for(int i=0; i<=len; i++) {

            if(str[i]=='.' || i==len) {
                temp[len_temp] = '\0';
                int num = atoi(temp);
                len_temp=0;
                do {
                    temp[len_temp++] = num%8 +'0';
                    num/=8;
                } while(num>0);
                temp[len_temp] ='\0';

                for(int i=0; i<len_temp/2; i++)
                    swap(temp[i],temp[len_temp-i-1]);
                strcat(ans,temp);
                int len_ans = strlen(ans);
                if(i!=len)
                    ans[len_ans]='.';
                len_temp=0;
            }
            else
                temp[len_temp++] = str[i];
        }
        printf("%s\n",ans);
    }
    return 0;
}

