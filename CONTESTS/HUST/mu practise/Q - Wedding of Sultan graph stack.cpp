#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOutput.txt","w",stdout);

    stack<char> parent;
    int t;
    scanf("%d",&t);
    for(int tcase =1; tcase<=t; tcase++)
    {
        char str[100001];
        scanf("\n%s",str);

        int len=strlen(str);
        printf("Case %d\n",tcase);
        if(len==2)
        {
            printf("%c = 0\n",str[0]);
            continue;
        }

        int connection[30];
        for(int i=0; i<26; i++)
            connection[i]=INT_MIN;

        parent.push(str[0]);
        connection[str[0]-'A']=0;

        int i=1;
        while(!parent.empty())
        {
            if(str[i] == parent.top())
            {
                if(connection[parent.top()-'A'] == INT_MIN)
                    connection[parent.top()-'A'] =1;
                parent.pop();
            }
            else
            {
                if(connection[parent.top()-'A'] == INT_MIN)
                    connection[parent.top()-'A']=2;
                else
                    connection[parent.top()-'A']++;
                parent.push(str[i]);
            }
            i++;
        }


        for(int i=0; i<26; i++) {
            if(connection[i]!= INT_MIN) {
                printf("%c = %d\n",i+'A',connection[i]);
            }
        }
    }
    return 0;
}
