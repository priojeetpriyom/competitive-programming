
class suf{
public:
    int idx;
    int rank1, rank2;

    void set(int i, int r1, int r2) {
        idx = i;
        rank1=r1;
        rank2 = r2;
//        cout<<"idx "<<idx<<" rank1 "<<rank1<<" rank2 "<<rank2<<endl;
    }
};

bool cmp(suf a, suf b) {
    if(a.rank1!= b.rank1)
        return a.rank1< b.rank1;
    return a.rank2 < b.rank2;
}

int RANK[100] [MX];
int power[100];
int suffixs[MX];

void build_suffix_array(string s) { //use one based indexing and lowercase letters
    int len = s.size()-1;

    for(int i=1; i<= len; i++) {
        s[i] = tolower(s[i]);
        RANK[0] [i] = (int)(s[i]- 'a');
    }
    for(int i=0; i<31; i++)
        power[i] = 1<<i;


    int step =1;

    for(int i=1; power[i-1]<len; i++, step++) {
//        cout<<" i "<<i<<endl;
        suf l[len+5];
        for(int j=1; j<=len; j++) {
            l[j].set(j, RANK[i-1][j], (j+ power[i-1]<=len ? RANK[i-1] [j+power[i-1]]: -1));
        }
//        for(int j=1; j<=len; j++) {
//            cout<<"j "<<j<<" idx "<<l[j].idx<<" rank1 "<<l[j].rank1<<" rank2 "<<l[j].rank2<<endl;
//        }

        sort(l+1, l+len+1, cmp);


        for1(j, len) {
//            cout<<" j "<<j<<" l[j].idx "<<l[j].idx<<endl;
            RANK[i][ l[j].idx ] = (j>1 && l[j].rank1 == l[j-1].rank1 && l[j].rank2 == l[j-1].rank2)? RANK[i][l[j-1].idx] : j;
        }

    }

    step--;

//    cout<<"step "<<step<<endl;
//    int ans[MX];
    for(int j=1; j<=len; j++)
        suffixs[RANK[step] [j]] = j;

    for(int j=1; j<=len; j++)
        cout<<"suffix[j] "<<suffixs[j]<<" "<<s.substr(suffixs[j])<<endl;





}
