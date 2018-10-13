

// dp approach

ll NCR(int n, int r) {
    if(n<r)
      return 0;
    if(n==r)
      return 1;
    if(r==1)
      return n;

    ll &ret = ncr[n][r];

    if(~ret)
      return ret;

    ret = NCR(n-1, r) + NCR(n-1, r-1);

    // if(ret>= mod)
    //   ret%= mod;

    return ret;

}


//modular-inverse approach


ll big_mod(ll n, ll pw) {

  if(pw==0)
    return 1;

  ll ret = big_mod(n, pw/2);

  ret*=ret;
  if(ret>=mod)
    ret%=mod;

  if(pw&1)
    ret*=n;


    if(ret>=mod)
      ret%=mod;

    return ret;

}


ll NCR(int n, int r) {

    // cout<<"called n "<<n<<" r "<<r<<endl;
  if(n<r)
    return 0;
  if(n==r)
    return 1;
  if(r==1)
    return n;
  if(r==0)
    return 1;


  ll ret = fact[n];

  ret = ret * big_mod((fact[r]*fact[n-r])%mod, mod-2);

  // cout<<"n "<<n<<" r "<<r<<" fact[n] "<<fact[n]<<" ret "<<ret<<endl;
  if(ret>=mod)
    ret%=mod;


  return ret;

}
