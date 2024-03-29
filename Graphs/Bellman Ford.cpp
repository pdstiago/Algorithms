struct Edge{
    int v, u, cost;
    Edge(int v, int u, int cost) : v(v), u(u), cost(cost) {}
};
struct Ford{ // Ford ford(n, m); O(VE)
    int n, m;
    vector<Edge> edges;
    vector<ll> dist;

    Ford(int n, int m) : n(n), m(m), dist(n+1, INFL) {}

    void add_edge(int v, int u, int cost){
        edges.emplace_back(v, u, cost);
    }

    ll bellman(int s, int t){
        dist[s]=0;
        for(int k=1; k<n; k++){
            for(int i=0; i<m; i++){
                int a=edges[i].v, b=edges[i].u, c=edges[i].cost;
                if(dist[a]!=INFL && dist[b]>dist[a]+c){
                    dist[b]=dist[a]+c;
                }
            }
        }
        for(int i=0; i<m; i++){
            int a=edges[i].v, b=edges[i].u, c=edges[i].cost;
            if(dist[a]!=INFL && dist[b]>dist[a]+c){
                return -1;
            }
        }
        return dist[t];
    }
};
