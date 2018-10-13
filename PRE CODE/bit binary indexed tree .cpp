
//----------one based indexing



//reads a single position in logN.
int readSingle(int idx){
int sum = tree[idx]; // this sum will be decreased
if (idx > 0){ // the special case
    int z = idx - (idx & -idx);
    idx--; // idx is not important anymore, so instead y, you can use idx
    while (idx != z){ // at some iteration idx (y) will become z
        sum -= tree[idx];
// substruct tree frequency which is between y and "the same path"
        idx -= (idx & -idx);
    }
}
return sum;
}

ll tree_bit[MX];

int lim;
void update_bit(int idx, int val) { //logN operation. one based indexing
    while(idx<= lim) {
        tree_bit[idx]+=val;
        idx += (idx & -idx);
    }
}

ll query_bit(int idx) {
    if(!idx)
      return 0;
    ll sum=0;
    while(idx!=0) {
        sum+= tree_bit[idx];
        idx-= (idx & -idx);
    }
    return sum;
}



// BINARY SEARCH ON CUMULATIVE SUM IN OlonN

// If in the tree exists more than one index with the same
// cumulative frequency, this procedure will return
// some of them

// bitMask - initialy, it is the greatest bit of MaxIdx
// bitMask stores the current interval that should be searched
int find(int cumFre){
  int idx = 0; // this variable will be the output

  while (bitMask != 0){
     int tIdx = idx + bitMask; // the midpoint of the current interval
     bitMask >>= 1; // halve the current interval
     if (tIdx > MaxIdx) // avoid overflow
       continue;
     if (cumFre == tree[tIdx]) // if it is equal, simply return tIdx
       return tIdx;
     else if (cumFre > tree[tIdx]){
       // if the tree frequency "can fit" into cumFre,
       // then include it
       idx = tIdx; // update index
       cumFre -= tree[tIdx]; // update the frequency for the next iteration
     }
 }
 if (cumFre != 0) // maybe the given cumulative frequency doesn't exist
   return -1;
 else
   return idx;
}

// If in the tree exists more than one index with a same
// cumulative frequency, this procedure will return
// the greatest one
int findG(int cumFre){
  int idx = 0;

  while (bitMask != 0){
    int tIdx = idx + bitMask;
    bitMask >>= 1;
    if (tIdx > MaxIdx)
      continue;
    if (cumFre >= tree[tIdx]){
      // if the current cumulative frequency is equal to cumFre,
      // we are still looking for a higher index (if exists)
      idx = tIdx;
      cumFre -= tree[tIdx];
    }
  }
  if (cumFre != 0)
    return -1;
  else
    return idx;
}




/// --------- 2D bit

void update(int x , int y , int val){
    int y1;
    while (x <= max_x){
        y1 = y;
        while (y1 <= max_y){
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

ll query(int x , int y , int val){
    ll ret=0;
    int y1;
    while (x){
        y1 = y;
        while (y1){
            ret+= tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }
    return ret;
}
