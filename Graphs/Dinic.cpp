struct Edge{
    int v, u;
    ll cap, flow=0;
    Edge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
struct Dinic{ //Dinic dinic(n, 1, n); O(V²E)
    int n, m=0, s, t;
    vector<Edge> edges;
    vector<vector<int> > vec;
    vector<int> lv, pos;
    queue<int> fila;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t){
        vec.resize(n+1);
        lv.resize(n+1);
        pos.resize(n+1);
    }
 
    void add_edge(int v, int u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        vec[v].pb(m);
        vec[u].pb(m+1);
        m+=2;
    }
 
    int bfs(){
        while(!fila.empty()){
            int v=fila.front();
            fila.pop();
            for(int i:vec[v]){
                if(edges[i].cap-edges[i].flow<1) continue;
                if(lv[edges[i].u]!=-1) continue;
 
                lv[edges[i].u]=lv[v]+1;
                fila.push(edges[i].u);
            }
        }
        return lv[t]!=-1;
    }
 
    ll dfs(int v, ll menor) {
        if(!menor) return 0;
        if(v==t) return menor;
 
        for(int& j=pos[v]; j<sz(vec[v]); j++){
            int i=vec[v][j];
            int u=edges[i].u;
 
            if(lv[v]+1!=lv[u] || edges[i].cap-edges[i].flow<1) continue;
 
            ll agr=dfs(u, min(menor, edges[i].cap-edges[i].flow));
            if(!agr) continue;
 
            edges[i].flow+=agr;
            edges[i^1].flow-=agr;
 
            return agr;
        }
        return 0;
    }
 
    ll max_flow(){
        ll flow=0;
        while(1){
            fill(lv.begin(), lv.end(), -1);
 
            lv[s]=0;
            fila.push(s);
 
            if(!bfs()) break;
 
            fill(pos.begin(), pos.end(), 0);
 
            while(ll atual=dfs(s, INFL)) flow+=atual;
        }
        return flow;
    }
    void recap(){
        for(int i=0; i<(int)edges.size(); i+=2){
            if(lv[edges[i].v]>=0 && lv[edges[i].u]==-1){
                cout << edges[i].v << " " << edges[i].u << endl;
            }
        }
    }
};
