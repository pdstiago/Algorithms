struct Hop{ // O(sqrt(V)*E), V number of vertices and E number of edges
    int n, m;
    vector<vector<int> > vec;
    vector<int> pairn, pairm, dist;
    queue<int> fila;

    Hop(int n, int m) : n(n), m(m), vec(n+1), dist(n+1), pairn(n+1), pairm(m+1) {}

    void add_edge(int v, int u) {
        vec[v].push_back(u);
    }

    int bfs(){
        for(int i=1; i<=n; i++){
            if(!pairn[i]) dist[i]=0, fila.push(i);
            else dist[i]=INF;
        }
        dist[0]=INF;
        while(!fila.empty()){
            int v=fila.front();
            fila.pop();
            if(dist[v]<dist[0]){
                for(int i:vec[v]){
                    if(dist[pairm[i]]==INF) dist[pairm[i]]=dist[v]+1, fila.push(pairm[i]);
                }
            }
        }
        return dist[0]!=INF;
    }

    int dfs(int v){
        if(!v) return 1;
        for(int i:vec[v]){
            if(dist[pairm[i]]==dist[v]+1){
                if(dfs(pairm[i])){
                    pairm[i]=v, pairn[v]=i;
                    return 1;
                }
            }
        }
        dist[v]=INF;
        return 0;
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

    vector<pair<int, int> > pairs(){
        vector<pair<int, int> > ans;
        for(int i=1; i<=n; i++){
            if(pairn[i]) ans.push_back({i, pairn[i]});
        }
        return ans;
    }
};
