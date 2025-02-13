// O(N*M)
// 1 - indexed
struct Kuhn {
    int n, m, t = 0;
    vector<int> memo, pai, filho;
    vector<vector<int> > vec;

    Kuhn(int n, int m) : n(n), m(m), memo(n+1), pai(n+1), filho(n+1), vec(n+1) {}

    void add_edge(int a, int b){
        vec[a].push_back(b);
    }

    bool dfs(int x){
        if(memo[x] == t) return 0;
        memo[x]=t;
        for(int i:vec[x]){
            if(!pai[i]){
                pai[i] = x, filho[x] = i;
                return 1;
            }
        }
        for(int i:vec[x]){
            if(dfs(pai[i])){
                pai[i]=x, filho[x]=i;
                return 1;
            }
        }
        return 0;
    }
    
    int solve(){
        int resp = 0, cur = 1;
        while(cur){
            cur = 0, t++;
            for(int i=1; i<=n; i++){
                if(!filho[i]) cur+=dfs(i);
            }
            resp+=cur;
        }
        return resp;
    }
};
