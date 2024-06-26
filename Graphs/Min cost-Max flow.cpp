struct min_cost{ // O(F*(V+E)logV), F being the amount of flow
    int n, m=0;
    ll eps=1e-10;
    vector<int> ptr, nxt, zu, pari;
    vector<ll> capa, cost, pot, dist, flows, slopes;
    vector<bool> vis;

    min_cost(int n) : n(n), ptr(n, -1), dist(n), vis(n), pari(n) {}

    void add_edge(int u, int v, ll w, ll c){
        nxt.push_back(ptr[u]); zu.push_back(v); capa.push_back(w); cost.push_back(c); ptr[u] = m++;
        nxt.push_back(ptr[v]); zu.push_back(u); capa.push_back(0); cost.push_back(-c); ptr[v] = m++;
    }
    // You can pass t=-1 to find a shortest path to each vertex
    void shortest(int s, int t){
        using E = pair<ll, int>;
        priority_queue<E, vector<E>, greater<E> > fila;

        for(int i=0; i<n; i++) dist[i]=INFL, vis[i]=false;

        for(fila.emplace(dist[s]=0, s); !fila.empty();){
            ll c=fila.top().first;
            int u=fila.top().second; 
            fila.pop();

            if(vis[u]) continue;
            vis[u]=true;

            if(u==t) return;

            for(int i=ptr[u]; ~i; i=nxt[i]){
                if(capa[i]>eps){
                    int v=zu[i];
                    ll cc=c+cost[i]+pot[u]-pot[v];
                    if(dist[v]>cc){
                        fila.emplace(dist[v]=cc, v);
                        pari[v]=i;
                    }
                }
            }
        }
    }

    pair<ll, ll> run(int s, int t, ll limFlow=INFL){
        pot.assign(n, 0);
        flows={0};
        slopes.clear();

        while(1){
            bool upd=false;
            for(int i=0; i<m; i++){
                if(capa[i]>eps){
                    int u=zu[i^1], v=zu[i];
                    ll cc=pot[u]+cost[i];
                    if(pot[v]>cc+eps){
                        pot[v]=cc, upd=true; 
                    }
                }
            }
            if(!upd) break;
        }
        ll flow=0, tot_cost=0;
        while(flow<limFlow){
            shortest(s, t);
            ll f=limFlow-flow;
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

    vector<pair<int, int> > recap(){
        vector<pair<int, int> > resp;
        for(int i=0; i<m; i++){
            if(i%2==0 && !capa[i]) resp.push_back({zu[i^1], zu[i]});
        }
        return resp;
    }
};
