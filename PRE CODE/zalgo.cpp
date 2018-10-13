void z_algo(const char s[], int lens, int z[], int offset) { // used zero based indexing. use offset to convert it to one based
//    vector<int> z(lens);
//    for(int i=0; i<lens; i++)
//        cout<<z[i]<<" ";
//    cout<<endl;
//    z[0]=0;
//    mem(z, 0)
    for(int i=1, l=0, r=0; i<lens; i++) {
//        z[i]=0;
        if(i<=r) {
            z[i] = min(r-i+1, z[ i-l ]);
        }

        while(i+ z[i]<lens && s[z[i]+offset ] == s[i+z[i]+offset])
            z[i]++;

        if(i+z[i]-1 > r) {
            l = i, r = i+z[i]-1;
        }

//        cout<<"i "<<i<<" l "<<l<<" r "<<r<<" z_i "<<z[i]<<endl;
    }

//    return z;
}
