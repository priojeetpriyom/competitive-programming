#include <bits/stdc++.h>
using namespace std;

char str[200100];
queue<char> Q;
int main()
{
//    freopen("myOutput.txt","w",stdout);

    while(scanf("%s",str)!=EOF) {
        int len = strlen(str);
        bool pairExists=true;
        for(int i=0; i<len; i++)
            Q.push(str[i]);
//            printf("size %d\n",Q.size());
        while(pairExists) {
            pairExists=false;
            len = Q.size()-1;
            char a,b;
            if(len>0) {
                b=Q.front();
//            printf("first %c\n",b);
            Q.pop();
            }
            for(int i=0; i<len; i++) {
                a=b;
                if(Q.empty())
                {
                    Q.push(a);
                    break;
                }
                b= Q.front();
                Q.pop();
                if(a!=b)
                {
                    Q.push(a);
                    if(i==len-1)
                        Q.push(b);
                } else{
                        if(!Q.empty()){


                            i++;
                            if(i<len-1 ){
                                b=Q.front();
                                Q.pop();
                                }
                        }
                        pairExists=true;
                }
            }
        }
        if(Q.empty())
        {
            printf("-1\n");
            continue;
        }
        while(!Q.empty()){
            printf("%c",Q.front());
            Q.pop();
            }
            printf("\n");

    }

    return 0;
}

