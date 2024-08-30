template<class flow_t, class cost_t> struct min_cost{ // O(F*(V+E)logV), F being the amount of flow
    static constexpr flow_t FLOW_EPS = flow_t(1e-10);
	static constexpr flow_t FLOW_INF = numeric_limits<flow_t>::max();
	static constexpr cost_t COST_EPS = cost_t(1e-10);
	static constexpr cost_t COST_INF = numeric_limits<cost_t>::max();

    int n, m=0;
    vector<int> ptr, nxt, zu, pari;
    vector<flow_t> capa, flows;
    vector<cost_t> cost, pot, dist, slopes;
    vector<bool> vis;

    min_cost(int n) : n(n), ptr(n, -1), dist(n), vis(n), pari(n) {}

    void add_edge(int u, int v, flow_t w, cost_t c){
        nxt.push_back(ptr[u]); zu.push_back(v); capa.push_back(w); cost.push_back(c); ptr[u] = m++;
        nxt.push_back(ptr[v]); zu.push_back(u); capa.push_back(0); cost.push_back(-c); ptr[v] = m++;
    }
    // You can pass t=-1 to find a shortest path to each vertex
    void shortest(int s, int t){
        using E = pair<cost_t, int>;
        priority_queue<E, vector<E>, greater<E> > fila;

        for(int i=0; i<n; i++) dist[i]=COST_INF, vis[i]=false;

        for(fila.emplace(dist[s]=0, s); !fila.empty();){
            cost_t c=fila.top().first;
            int u=fila.top().second; 
            fila.pop();
            if(vis[u]) continue;
            vis[u]=true;
            if(u==t) return;
            for(int i=ptr[u]; ~i; i=nxt[i]){
                if(capa[i]>FLOW_EPS){
                    int v=zu[i];
                    cost_t cc=c+cost[i]+pot[u]-pot[v];
                    if(dist[v]>cc) fila.emplace(dist[v]=cc, v), pari[v]=i;
                }
            }
        }
    }

    auto run(int s, int t, flow_t limFlow=FLOW_INF){
        pot.assign(n, 0);
        flows={0};
        slopes.clear();

        while(1){
            bool upd=false;
            for(int i=0; i<m; i++){
                if(capa[i]>FLOW_EPS){
                    int u=zu[i^1], v=zu[i];
                    cost_t cc=pot[u]+cost[i];
                    if(pot[v]>cc+COST_EPS) pot[v]=cc, upd=true; 
                }
            }
            if(!upd) break;
        }
        flow_t flow=0; cost_t tot_cost=0;
        while(flow<limFlow){
            shortest(s, t);
            flow_t f=limFlow-flow;
            if(!vis[t]) break;

            for(int i=0; i<n; i++) pot[i]+=min(dist[i], dist[t]);

            for(int v=t; v!=s;){ 
                int i=pari[v];
                if(f>capa[i]) f=capa[i];
                v=zu[i^1];
            }

            for(int v=t; v!=s;){
                int i=pari[v];
                capa[i]-=f, capa[i^1]+=f, v=zu[i^1];
            }
            
            flow+=f, tot_cost+=f*(pot[t]-pot[s]);
            flows.push_back(flow), slopes.push_back(pot[t]-pot[s]);
        }
        return make_pair(flow, tot_cost);
    }

    auto recap(){
        vector<pair<int, int> > resp;
        for(int i=0; i<m; i++){
            if(i%2==0 && !capa[i]) resp.push_back({zu[i^1], zu[i]});
        }
        return resp;
    }
};
