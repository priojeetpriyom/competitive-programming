// suffix array lcp of two suffix pairs O(logN)

int lcp(int i, int j) {
    int ret = 0;

    for (int k = step; k >= 0; k--) {
        if (RANK[k][i] == RANK[k][j]) {
            ret += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ret;
}
