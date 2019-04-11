
#include<bits/stdc++.h>
using namespace std;
int main ()
{
    string s[11];
    int ara[11];
   int n;
    while(scanf("%d",&n)==1) {
        for(int i=0; i<n; i++)
        {
            cin>>s[i]>>ara[i];
        }

        int x=0;
        int mess=0;

        for(int k=1; k<101; k++) {
                int x=k;
            for(int i=0; i<n;i++)
        {
            if(s[i]=="ADD") {
                x+= ara[i];
            }
            else if(s[i]=="SUBTRACT") {
                x-=ara[i];
                if(x<0)
                {
                    mess++;
                    break;
                }
            }
            else if(s[i]=="MULTIPLY") {
                x*=ara[i];
            }

            else {
                if(x%ara[i]==0) {
                    x/=ara[i];
                }
                else
                {
                    mess++;
                    break;
                }

            }
        }
        //printf("Fsd");
        }

        printf("%d\n",mess);
    }

    return 0;
}

