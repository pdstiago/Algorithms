struct PR{ //O(VE+V²*sqrt(E)), worst case O(V³)
    int n, s, t;
    vector<int> lv;
    vector<ll> ex;
    vector<vector<ll> > cap, flow;

    PR(int n, int s, int t) : n(n), s(s), t(t), cap(n+1, vector<ll>(n+1), flow(n+1, vector<ll>(n+1),
    ex(n+1), lv(n+1) {}

    void add_edge(int v, int u, ll x){
        cap[v][u]+=x;
    }
    
    void push(int u, int v){
        ll d=min(ex[u], cap[u][v]-flow[u][v]);

        flow[u][v]+=d;
        flow[v][u]-=d;

        ex[u]-=d;
        ex[v]+=d;
    }

    void relabel(int u){
        int d=INF;
        for(int i=1; i<=n; i++){
            if(cap[u][i]-flow[u][i]){
                d=min(d, lv[i]);
            }
        }
        if(d<INF){
            lv[u]=d+1;
        }
    }

    vector<int> find_v(){
        vector<int> max_h;
        for(int i=1; i<=n; i++){
            if(i!=s && i!=t && ex[i]){
                if(!max_h.empty() && lv[i]>lv[max_h[0]]){
                    max_h.clear();
                }
                if(max_h.empty() || lv[i]==lv[max_h[0]]){
                    max_h.push_back(i);
                }
            }
        }
        return max_h;
    }
    ll max_flow(){
        lv[s]=n;
        ex[s]=INFL;

        for(int i=1; i<=n; i++){
            if(i!=s) push(s, i);
        }

        vector<int> atual;
        while(!(atual=find_v()).empty()){
            for(int i:atual){
                int ok=0;
                for(int j=1; j<=n && ex[i]; j++){
                    if(cap[i][j]-flow[i][j] && lv[i]==lv[j]+1){
                        push(i, j);
                        ok=1;
                    }
                }
                if(!ok){
                    relabel(i);
                    break;
                }
            }
        }

        ll total=0;
        for(int i=1; i<=n; i++){
            total+=flow[i][t];
        }
        return total;
    }
};
