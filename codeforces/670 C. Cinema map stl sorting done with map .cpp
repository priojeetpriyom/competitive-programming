#include<bits/stdc++.h>
using namespace std;

int ara[200100];

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
        scanf("%d", &x);
        ara[i] = x;
        movieIdx[x]=i+1;
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d", &x);
        int a=0,b=0;
        if(audSub.find(ara[i])!=audSub.end() && lang.find(audSub[ara[i]]) != lang.end())
            a = lang[audSub[ara[i]]];
        if(lang.find(x) != lang.end())
            b = lang[x];
        if(a<=b)
        {
//            printf("ara %d i %d\n", ara[i], i);
            audSub[ara[i] ] = x;
            movieIdx[ara[i]] = i+1;

        }
    }

    map<int, int>:: iterator it = audSub.begin();
    int mxAudio=0, mxSub=0, idx=-1;
    for( ; it!= audSub.end(); it++)
    {
        if(lang.find(it->first) != lang.end())
        {
            if(lang[it->first] > mxAudio)
            {
                mxAudio = lang[it->first];
                if(lang.find(it->second)!= lang.end() )
                    mxSub = lang[it->second];
                else
                    mxSub =0;

                idx = movieIdx[it->first];
            }
            else if(lang[it->first] == mxAudio && lang.find(it->second) != lang.end() && lang[it->second] > mxSub)
            {
                mxSub = lang[it->second];
                idx = movieIdx[it->first];
            }
        }
    }
//    printf("idx %d\n", idx);
    if(idx == -1)
    {
        idx=1;
        mxSub =0;
        for(int i=0; i<m; i++) {
            if((lang.find(audSub[ara[i] ]) != lang.end() ) && lang[audSub[ara[i]] ]> mxSub) {
//                printf("i %d sub %d idx %d\n", i, audSub[ara[i]], movieIdx[ara[i]]);
                mxSub = lang[audSub[ara[i]]];
                idx = movieIdx[ara[i]];
            }
        }
    }
//    printf("sub %d\n", audSub[9]);
//    for(int i=0 ; i<m; i++)
//    {
//        if(lang.find(ara[i])!= lang.end() && lang[ara[i]] == mxAudio && ((lang.find(audSub[ara[i]]) != lang.end() && lang[audSub[ara[i]]] == mxSub)))
//        {
//
//            cout<<i+1<<endl;
//            return 0;
//        }
//    }

    cout<<idx<<endl;


    return 0;

}

