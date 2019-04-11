#include <bits/stdc++.h>
using namespace std;
//#define fr( i, lim) (int i=0; i<lim; i++)

int main()
{
//    freopen("myOutput.txt","w",stdout);

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        int x,n_boxes,box_type[10],mx=INT_MIN,mx_pos;
        bool tie=false;
        scanf("%d",&n);
        for(int z=0; z<n; z++)
        {
            scanf("%d",&n_boxes);

            memset(box_type,0,sizeof(box_type));


            for(int i=0; i<n_boxes; i++)
            {

                scanf("%d",&x);
                box_type[x]++;
            }

//            for(int i=1; i<7; i++)
//                printf("%d ",box_type[i]);
//            break;

            int cnt=1,cnt_mx=0;
            while(cnt>0)
            {
                cnt=0;
                for(int i=1; i<7; i++)
                {
                    if(box_type[i]>0)
                    {
                        cnt++;
                        box_type[i]--;
                    }

                }
//                for(int i=1; i<7; i++)
//                    printf("%d ",box_type[i]);
//                printf("\ncnt %d\n",cnt);

                cnt_mx+=cnt;
                if(cnt==6)
                    cnt_mx+=4;
                else if(cnt==5)
                    cnt_mx+=2;
                else if(cnt==4)
                    cnt_mx+=1;

            }
            if(cnt_mx>mx)
            {
                tie=false;
                mx_pos=z;
                mx=cnt_mx;
            }
            else if(cnt_mx==mx)
            {
                tie=true;
            }

        }
        if(tie)
            printf("tie\n");
        else if(mx_pos==0)
            printf("chef\n");
        else
            printf("%d\n",mx_pos+1);
    }

    return 0;
}

