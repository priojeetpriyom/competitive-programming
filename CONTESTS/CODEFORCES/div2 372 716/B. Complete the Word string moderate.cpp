#include <bits/stdc++.h>
using namespace std;
int chars[30],gaps,missing;
    char str[50010];

bool count_chars(int i, int j) {
    memset(chars,0,sizeof(chars));

//    for(int k=0; k<26; k++)
//        printf("%d ",chars[k]);
//    printf("i %d j %d\n",i,j);
    gaps=0;
    for(; i<j; i++) {
        if(str[i] == '?')
            gaps++;
        else
            chars[str[i]-'A']++;
//        if(str[i]!='?' && chars[str[i]-'A']>1) {
////            printf("aitar karone %d %c\n",chars[str[i]-'A'],str[i]);
//            return false;
//        }
    }
//        for(int k=0; k<26; k++)
//        printf("%d ",chars[k]);
    int k=0;
    for(; k<26; k++)
    {
        if(chars[k]>1)
            return false;

    }
//    printf("gaps %d missing %d\n",gaps,missing);

    return true;
}
int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);


    scanf("\n%s",str);
    int len = strlen(str),done=0;

    for(int i=0,j=26;j<=len; i++,j++) {
        if(count_chars(i,j)==true) {

            done=1;
            if(gaps==0) {
                break;
            }

            int x=0;
            while(chars[x]!=0)
                    x++;
            for( ; i<j; i++) {

                if(str[i] == '?'){
//                    printf("%c",x+'A');
                    str[i] = x+'A';
                    x++;
                    while(chars[x]!=0 && x<28)
                        x++;
                    }
            }
            break;
        }
    }

    for(int i=0; i<len; i++)
        if(str[i]=='?')
            str[i]='A';


    if(done==0)
        printf("-1");
    else
        printf("%s",str);
    printf("\n");
    return 0;
}

