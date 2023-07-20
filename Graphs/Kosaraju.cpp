struct KOSA{
    int n;
    vector<int> memo, comp, st;
    vector<vector<int> > vec, rvec, scc;

    KOSA(int n) : n(n){
        memo.resize(n+1);
        comp.resize(n+1);
        vec.resize(n+1);
        rvec.resize(n+1);
        scc.resize(n+1);
    }

    void add_edge(int a, int b){
        vec[a].push_back(b);
        rvec[b].push_back(a);
    }

    void dfs(int x){
        memo[x]=1;
        for(int i:vec[x]){
            if(!memo[i]) dfs(i);
        }
        st.pb(x);
    }

    void dfs2(int x, int c){
        comp[x]=c;
        for(int i:rvec[x]){
            if(!comp[i]) dfs2(i, c);
        }
    }

    void build(){
        int cont=0;
        for(int i=1; i<=n; i++){
            if(!memo[i]) dfs(i);
        }
        reverse(st.begin(), st.end());
        for(int i:st){
            if(!comp[i]){
                dfs2(i, ++cont);
            }
        }
        for(int i=1; i<=n; i++){
            for(int j:vec[i]){
                if(comp[i]==comp[j]) continue;
                scc[comp[i]].push_back(comp[j]);
            }
        }
    }
};
