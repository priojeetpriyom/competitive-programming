#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myOut.txt", "w", stdout);
    int len;
    string s;
    cin>>len>>s;
    int d=0, r=0, d_count=0, r_count=0;
    do
    {
//        printf("len %d %s\n", len, s.c_str());
        for(int i=0; i<len; i++)
        {
            if(s[i] == 'D')
            {
                if(r>0)
                {
                    r--;
                    s[i] = "x";
//                    s.erase(s.begin()+i);
//                    i--;
////                    d_count--;
//                    len--;
//                d--;
                }
                else
                {

//                    d_count++;
//                    if(r_count>0)
//                        r_count--;
//                    else
                        d++;
                }
            }
            else if(s[i] == 'R')
            {
                if(d>0)
                {
                    s[i] = "x";
//                    s.erase(s.begin()+i);
////                    r_count--;
//                    i--;
//                    len--;
                    d--;
//                r--;
                }
                else
                {

                    r_count++;
//                    if(d_count>0)
//                        d_count--;
//                    else
                        r++;

                }
            }
//    printf("r_count %d d_count %d r %d d %d STR %s\n",r_count, d_count, r, d, s.c_str());
        }
    } while((!( (d>len) || (r>len) )) );
//    if(r_count>d_count)
    if(r>d)
        printf("R");
    else
        printf("D");
    return 0;
}


