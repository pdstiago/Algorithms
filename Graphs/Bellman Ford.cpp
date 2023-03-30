struct Edge{
    int u, v, cost;
    Edge(int v, int u, int cost) : v(v), u(u), cost(cost) {}
};
struct Ford{ // Ford ford(n, m); O(VE)
    int n, m;
    vector<Edge> edges;
    vector<vector<int> > rvec;
    vector<int> memo;
    vector<ll> dist;

    Ford(int n, int m) : n(n), m(m){
        rvec.resize(n+1);
        dist.resize(n+1, INFL);
        memo.resize(n+1);
    }

    void add_edge(int v, int u, int cost){
        edges.emplace_back(v, u, cost);
        rvec[u].pb(v);
    }

    void dfs(int x){
        memo[x]=1;
        for(int i:rvec[x]) if(!memo[i]) dfs(i);
    }

    ll bellman(){
        dfs(n);
        dist[1]=0;
        for(int k=1; k<n; k++){
            for(int i=0; i<m; i++){
                int a=edges[i].v, b=edges[i].u, c=edges[i].cost;
                if(dist[a]<INFL && dist[b]>dist[a]+c){
                    dist[b]=dist[a]+c;
                }
            }
        }
        for(int i=0; i<m; i++){
            int a=edges[i].v, b=edges[i].u, c=edges[i].cost;
            if(dist[a]<INFL && dist[b]>dist[a]+c && memo[b]){
                return -1;
            }
        }
        return dist[n];
    }
};
