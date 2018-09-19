#include<bits/stdc++.h>
using namespace std;

int ara[200100],  ara2[200100];

int main()
{
//    freopen("myOut.txt", "w", stdout);
    int n,m;
    map<int, int> lang, movieIdx, audSub;
    int x;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        lang[x]++;

    }

    cin>>m;

    for(int i=0; i<m; i++)
    {
        scanf("%d", &ara[i]);
//        ara[i] = x;
//        movieIdx[x]=i+1;
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", &ara2[i]);
//        if(audSub.find(ara[i])!= audSub.end() && audSub[ara[i]] > x);
//        else
//            audSub[ara[i] ] = x;
    }

    map<int, int>:: iterator it = audSub.begin();
    int mxAudio=0, mxSub=0, idx=-1;
    for( int i=0; i<m; i++)
    {
        if(lang.find(ara[i]) != lang.end())
        {
            if(lang[ara[i] ] > mxAudio)
            {
                mxAudio = lang[ara[i] ];
                if(lang.find(ara2[i])!= lang.end() )
                    mxSub = lang[ara2[i] ];
                else
                    mxSub =0;

                idx = i+1;
            }
            else if(lang[ara[i] ] == mxAudio && lang.find( ara2[i]) != lang.end() && lang[ara2[i] ] > mxSub)
            {
                mxSub = lang[ara2[i]];
                idx = i+1;
            }
        }
    }
    if(idx == -1)
    {
        idx=1;
        mxSub =0;
        for(int i=0; i<m; i++) {
            if((lang.find(ara2[i]) != lang.end() ) && lang[ara2[i]]> mxSub) {
                mxSub = lang[ara2[i]];
                idx = i+1;
            }
        }
    }

        cout<<idx<<endl;

//    for(int i=0 ; i<m; i++)
//    {
//        if(lang.find(ara[i])!= lang.end() && lang[ara[i]] == mxAudio && (mxSub==0 || (lang.find(audSub[ara[i]]) != lang.end() && lang[audSub[ara[i]]] == mxSub)))
//        {
//
//            cout<<i+1<<endl;
//            break;
//        }
//    }



    return 0;

}

