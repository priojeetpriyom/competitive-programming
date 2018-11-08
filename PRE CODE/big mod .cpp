ll big_mod(int n, int pw,const ll& mod) {
  if(!pw)
    return 1;

  ll ret = big_mod(n, pw>>1, mod);
  ret*=ret;
  if(ret>=mod) ret%=mod;
  if(pw&1)
    ret*=n;

  if(ret>=mod) ret%=mod;
  return ret;
}
