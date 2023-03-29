struct Hopcroft{ //Hopcroft hop(n); O(sqrt(V)*E)
    int n;
    vector<vector<int> > vec;
    vector<int> pairn, pairm, dist;
    queue<int> fila;

    Hopcroft(int n) : n(n){
        vec.resize(n+1);
        dist.resize(n+1);
        pairn.resize(n+1);
        pairm.resize(n+1);
    }

    void add_edge(int v, int u) {
        vec[v].pb(u);
    }

    int bfs(){
        for(int i=1; i<=n; i++){
            if(!pairn[i]){
                dist[i]=0;
                fila.push(i);
            }else{
                dist[i]=INF;
            }
        }
        dist[0]=INF;
        
        while(!fila.empty()){
            int v=fila.front();
            fila.pop();

            if(dist[v]<dist[0]){
                for(int i:vec[v]){
                    if(dist[pairm[i]]==INF){
                        dist[pairm[i]]=dist[v]+1;
                        fila.push(pairm[i]);
                    }
                }
            }
        }
        return dist[0]!=INF;
    }

    int dfs(int v){
        if(v){
            for(int i:vec[v]){
                if(dist[pairm[i]]==dist[v]+1){
                    if(dfs(pairm[i])){
                        pairm[i]=v;
                        pairn[v]=i;
                        return 1;
                    }
                }
            }
            dist[v]=INF;
            return 0;
        }
        return 1;
    }

    int max_bip(){
        int resp=0;
        while(bfs()){
            for(int i=1; i<=n; i++){
                if(!pairn[i] && dfs(i)) resp++;
            }
        }
        return resp;
    }

    vector<pii> pairs(){
        vector<pii> ans;
        for(int i=1; i<=n; i++){
            if(pairn[i]) ans.pb({i, pairn[i]});
        }
        return ans;
    }
};
