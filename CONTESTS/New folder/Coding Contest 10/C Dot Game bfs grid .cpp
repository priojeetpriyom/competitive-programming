#include <bits/stdc++.h>
using namespace std;
char str[20] [20];
int row,col;
bool visited [20] [20];
int dir_r[5]= {0,0,1,-1};
int dir_c[5]= {1,-1,0,0};
queue<int> r,c;
int calculate(char mark) {
    int cnt=0;
    while(!r.empty()) {
        int i = r.front(),j = c.front();
        r.pop();
        c.pop();
        for(int k=0; k<4; k++) {
            if(dir_r[k]+i<= row && dir_r[k]+i>= 0 && dir_c[k]+j>=0 && dir_c[k]+j<=col && str[dir_r[k]+i][dir_c[k]+j] == mark && !visited[dir_r[k]+i] [dir_c[k]+j]) {
                visited[dir_r[k]+i] [dir_c[k]+j]=true;
                cnt++;
                r.push(dir_r[k]+i);
                c.push(dir_c[k]+j);
            }
        }
    }
    return cnt;
}


int main()
{
//    freopen("myIn.txt","r",stdin);
//    freopen("myOut.txt","w",stdout);
    while(scanf("%d %d", &col,&row)==2) {
        for(int i=0; i<row; i++) {
            scanf("\n%s",str[i]);
        }

        memset(visited,0, sizeof(visited));
int tutul=0;
    int afsa=0;
    for(int i =0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(!visited[i][j] && str[i][j]=='*') {
                 r.push(i);
                c.push(j);
                tutul= max(tutul,calculate('*'));

            }
        }
    }
//    printf("oka");
    for(int i =0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(!visited[i][j] && str[i][j]=='.') {
                 r.push(i);
                c.push(j);
                afsa= max(afsa,calculate('.'));

            }
        }
    }

    if(tutul>afsa) {
       printf("TULTUL WINS THE ROUND.\n");
    }else if(afsa>tutul) {
        printf("TASFIA WINS THE ROUND.\n");
    } else
        printf("NOBODY LOSES.\n");

    }
    return 0;
}

