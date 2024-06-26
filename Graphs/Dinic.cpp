struct Edge{
    int v, u;
    ll cap, flow=0;
    Edge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};
// O(min(V*max_flow, V²*E))
// Grafo com capacidades 1: O(min(M*sqrt(M), M*N^(2/3)))
// Todo vértice tem grau de entrada ou saída 1: O(M*sqrt(N))
struct Dinic{
    int n, m=0;
    vector<Edge> edges;
    vector<vector<int> > vec;
    vector<int> lv, pos;
    queue<int> fila;
 
    Dinic(int n) : n(n), vec(n+1), lv(n+1), pos(n+1) {}
 
    void add_edge(int v, int u, ll cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        vec[v].push_back(m);
        vec[u].push_back(m+1);
        m+=2;
    }
 
    int bfs(int t){
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
 
    ll dfs(int v, int t, ll menor) {
        if(!menor) return 0;
        if(v==t) return menor;
 
        for(int& j=pos[v]; j<(int)vec[v].size(); j++){
            int i=vec[v][j];
            int u=edges[i].u;
 
            if(lv[v]+1!=lv[u] || edges[i].cap-edges[i].flow<1) continue;
 
            ll agr=dfs(u, t, min(menor, edges[i].cap-edges[i].flow));
            if(!agr) continue;
 
            edges[i].flow+=agr;
            edges[i^1].flow-=agr;
 
            return agr;
        }
        return 0;
    }
 
    ll max_flow(int s, int t){
        ll flow=0;
        while(1){
            fill(lv.begin(), lv.end(), -1);
 
            lv[s]=0;
            fila.push(s);
 
            if(!bfs(t)) break;
 
            fill(pos.begin(), pos.end(), 0);
 
            while(ll atual=dfs(s, t, INFL)) flow+=atual;
        }
        return flow;
    }
    vector<pair<int, int> > recap(){
        vector<pair<int, int> > resp;
        for(int i=0; i<(int)edges.size(); i+=2){
            if(lv[edges[i].v]>=0 && lv[edges[i].u]==-1) resp.push_back({edges[i].v, edges[i].u});
        }
        return resp;
    }
};
