// Créditos: Caderno da UFMG
// O(NlogN)
struct SA{
	int n;
	string s;
	vector<int> sa, lcp, pos;
	vector<vector<int> > rank_subs;
	RMQ<int> rmq;

	vector<int> suffix_array() {
		s.push_back('$');

		int n=(int)s.size(), N=max(n, 260);
		vector<int> sa(n), rank(n);

		for(int i=0; i<n; i++) sa[i] = i, rank[i] = s[i];

		for(int k=0; k<n; k ? k*=2 : k++) {
			vector<int> nsa(sa), nrank(n), cnt(N);

			for(int i=0; i<n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[rank[i]]++;
			for(int i=1; i<N; i++) cnt[i]+=cnt[i-1];
			for(int i=n-1; i+1; i--) sa[--cnt[rank[nsa[i]]]] = nsa[i];

			for(int i=1, r=0; i<n; i++) nrank[sa[i]] = r += rank[sa[i]] != rank[sa[i-1]] || rank[(sa[i]+k)%n] != rank[(sa[i-1]+k)%n];

			rank = nrank;
			rank_subs.push_back(rank);
			//if(rank[sa[n-1]]==n-1) break;
		}
		s.pop_back();

		return vector<int>(sa.begin()+1, sa.end());
	}

	vector<int> build_lcp(){
		int n=(int)s.size(), k=0;
		vector<int> rank(n), lcp(n);
		for(int i=0; i<n; i++) rank[sa[i]] = i;

		for(int i=0; i<n; i++, k-=!!k){
			if(rank[i]==n-1) {k=0; continue;}
			int j=sa[rank[i]+1];
			while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
			lcp[rank[i]] = k;
		}
		return lcp;
	}

	SA() {}

	SA(string s) : s(s), n((int)s.size()), pos(n){
		sa = suffix_array();
		lcp = build_lcp();
		rmq = RMQ(lcp);
		for(int i=0; i<n; i++) pos[sa[i]]=i;
	}

	int get_lcp(int i, int j){ // lcp na posição i, indica o lcp das posições i e i+1 do sa
		if(i==j) return n-i;
		int l = pos[i], r = pos[j];

		if(l>r) swap(l, r);

		return rmq.query_min(l, r);
	}

	// string s = a + '+' + b;
	pair<int, int> lcs(int m){ // m é o tamanho da string a
		int maior = 0, pos = -1;
		for(int i=2; i<n; i++){
			if((sa[i]<m) != (sa[i-1]<m)){
				if(lcp[i-1]>maior) maior = lcp[i-1], pos = sa[i];
			}
		}
		return {maior, pos};
	}

	int compare(int i, int j, int tam){ // compara duas substrings de tamanho igual
		int k = __lg(tam);
		pair<int, int> a = {rank_subs[k][i], rank_subs[k][(i+tam-(1<<k))%n]};
		pair<int, int> b = {rank_subs[k][j], rank_subs[k][(j+tam-(1<<k))%n]};
		return a==b ? 0 : a<b ? -1 : 1;
	}

	ll distinct_subs(){ // n*(n+1)/2 - sum(lcp[i])
		ll resp = (ll)n*((ll)n+1)/2;
		return resp - accumulate(lcp.begin(), lcp.end(), 0LL);
	}
};
