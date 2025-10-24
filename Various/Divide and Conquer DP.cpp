/**
 * Author: Simon Lindholm
 * License: CC0
 * Source: Codeforces
 * Description: Given $a[i] = \min_{lo(i) \le k < hi(i)}(f(i, k))$ where the (minimal) optimal $k$ increases with $i$, computes $a[i]$ for $i = L..R-1$.
 * Status: tested on http://codeforces.com/contest/321/problem/E
 * Time: O((N + (hi-lo)) \log N * k)
 */
 
struct DP { ///start-hash
	vector<vector<int> > a;
	vector<int> old, cur;
	DP(const vector<vector<int> >&_a, int n): a(_a), old(n+1, INF), cur(n+1, INF) {}
	int C(int l, int r){
		return a[l][r];
	} ///end-hash
	int f(int ind, int k) { return old[k-1] + C(k, ind); } ///start-hash
	void store(int ind, int k, int v) { cur[ind] = v; }
	void rec(int L, int R, int LO, int HI) {
		if (L > R) return;
		int mid = (L + R) >> 1;
		pair<int, int> best(INF, LO);
		for(int k = LO; k <= min(HI, mid); ++k){
            best = min(best, make_pair(f(mid, k), k));
        }
		store(mid, best.second, best.first);
		rec(L, mid-1, LO, best.second);
		rec(mid+1, R, best.second, HI);
	}
}; ///end-hash

auto dp = DP(calc, n);
dp.old[0]=0;
for(int i=0; i<k; i++){
    dp.rec(1, n, 1, n);
    swap(dp.old, dp.cur);
}
return dp.old[n];