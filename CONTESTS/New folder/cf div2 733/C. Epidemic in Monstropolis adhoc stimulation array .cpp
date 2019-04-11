#include <bits/stdc++.h>
using namespace std;


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);

    int len1, len2;
    int seq[511],len_seq=0;
    char seq_char[511];
    int b[511];
    vector<int> a;

    scanf("%d", &len1);
    int x;
    for(int i=0; i<len1; i++)
    {
        scanf("%d",&x);
        a.push_back(x);
    }
    a.push_back(0);

    scanf("%d", &len2);

    for(int i=0; i<len2; i++)
        scanf("%d",&b[i]);

    int pos1=0, pos2=0;
    while(len1!= len2) {
//            printf("len1 %d len2 %d\n", len1, len2);
        bool dhuker = false;
        for(int i=pos1; i<len1; i++) {
//                printf("oka\n");
            if(a[i]== b[pos2]) {
                pos1++;
                pos2++;
            }
            else if(a[i]> b[pos2])
            {
                printf("NO\n");
                return 0;
            }
            else if(abs(a[i+1] - a[i]) > 0){
                dhuker = true;

                if(a[i]> a[i+1]) {
                    seq[len_seq] = i+1;
                    seq_char[len_seq++] = 'R';
                } else {
                    seq[len_seq] = i+2;
                    seq_char[len_seq++] = 'L';
                }

                a[i] += a[i+1];
                a.erase(a.begin()+i+1);
                len1--;

                for(int j=0 ;j< a.size(); j++)
                    printf("%d ",a[j]);
                printf("\n");
                break;
            }
        }
        if(!dhuker && a[pos1] < b[pos2])
        {
            printf("NO\n");
                return 0;
        }
    }

    for(int i=0; i< len1; i++)
        if(a[i]!= b[i])
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    for(int i=0; i<len_seq; i++)
        printf("%d %c\n", seq[i], seq_char[i]);




    return 0;
}
