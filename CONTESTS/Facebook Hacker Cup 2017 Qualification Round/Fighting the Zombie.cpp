
#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int t;
    cin>>t;

    for(int tc = 1; tc<=t; tc++) {
        int h, s;
        cin>>h>>s;
        cin.ignore();
        double best =0;
        while(s--) {
            char str[10];
            scanf("\n%s", str);
            int len = strlen(str);
            int z =0;

            //adjusting z
            for(int i=0; i<len; i++) {
                if(str[i] == '+') {
                    for(int j = i+1; j<len; j++) {
                        z = z*10 + (str[j] - '0');
                    }
                    h-=z;
                    break;
                } else if(str[i] == '-') {

                    for(int j = i+1; j<len; j++) {
                        z = z*10 + (str[j] - '0');
                    }
                    h+=z;
                    break;
                }
            }

             int x, y;



            for(int i=0; i<len; i++) {
                if(str[i] == 'd') {
                    for(int j = i+1; j<len; j++)
                        y = y* (str[j] - '0');
                    break;
                }

                x = x* (str[i] - '0');
            }




        }
    }

    return 0;
}
