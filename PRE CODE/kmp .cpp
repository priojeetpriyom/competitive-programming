
int failure[MX];



int get_substring_count(char text[], char pattern[], int lent, int lenp) {
    int t=0, p=0;
    int ret=0;
    while(true) {
        if(t==lent)
            return ret;

        if(text[t] == pattern[p]) {
            t++, p++;
        }
        else if(p==0) {
            t++;
        }
        else
            p = failure[p];

        if(p==lenp) {
            ret++;
            p=failure[p];
        }


//        cout<<"p "<<p<<" t "<<t<<" ret "<<ret<<endl;
     }
}


void build_failure(const char str[], int len) { // use zero based indexing


    for(int i=2; i<=len; i++) {
        int j = failure[i-1];
        while(true) {
            if(str[i-1] == str[j]) {
                failure[i] = j+1;
                break;
            }
            if(j==0) {
                failure[i]=0;
                break;
            }
            j = failure[j];
        }

//        cout<<"i "<<i<<" failure_i "<<failure[i]<<endl;
    }

}
