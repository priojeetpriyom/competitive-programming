#include <bits/stdc++.h>
//char gogol[100001], papple[31];
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,m,k, x, y;
    //char temp [11];
    string str[32][32], s;
    while(scanf("%d %d %d",&n, &m, &k)==3)
    {
        int lenStr=0;
        for(int i=0;i<31;i++)
            for(int j=0;j<32;j++)
                str[i] [j] = '\0';
        while(k--) {
            //scanf("\n%s",temp);
            cin>>s;
            bool cntinue= false;
            if(s[0] == '+') {
                scanf("%d %d",&x, &y);
                cin>>s;
                //
                while(str[x][y].length()>1)
                {
                    y++;
                    if(y>m)
                    {
                        y=1;
                        x++;
                        if(x>n)
                        {
                            cntinue=true;
                            break;
                        }
                    }
                }
                if(!cntinue)
                {
                    //printf("x %d y %d\n",x,y);
                    str[x] [y] = s;
                }
            }
            else {
                cin>>s;
                x=y= -1;
                for(int i=1;i<31;i++)
                    for(int j=1;j<31;j++)
                        if(s == str[i] [j])
                        {
                            x=i;
                            y=j;
                            str[x] [y]= '\0';
                            //cout<<"len "<<str[x][y].length()<<endl;
                            break;
                        }
                printf("%d %d\n",x, y);
            }
        }
    }
    return 0;
}
