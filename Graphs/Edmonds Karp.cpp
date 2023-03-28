struct Karp{ // Karp karp(n, m, 1, n); O(VE²)
    vector<vector<pii> > vec;
    vector<ll> cap;
    vector<pii> pai;
    int n, m=0, s, t;

    Karp(int n, int mf, int s, int t) : n(n), s(s), t(t){
        vec.resize(n+1);
        pai.resize(n+1);
        cap.resize(2*mf);
    }

    void add_edge(int v, int u, ll x){
        vec[v].pb({u, m});
        vec[u].pb({v, m+1});
        cap[m]=x;
        cap[m+1]=0;
        m+=2;
    }

    int bfs(){
        fill(parent.begin(), parent.end(), make_pair(-1,-1));
        pai[s]={0, 0};

        queue<pair<int, ll> > fila;
        fila.push({s, INFL});

        while(!fila.empty()){
            auto atual=fila.front();
            fila.pop();
            for(pii i:vec[atual.f]){
                if(pai[i.f].f==-1 && cap[i.s]){
                    pai[i.f]={atual.f, i.s};
                    ll flow=min(atual.s, cap[i.s]);
                    if(i.f==t) return flow;
                    fila.push({i.f, flow});
                }
            }
        }
        return 0;
    }

    ll max_flow(){
        ll flow=0, atual;
        
        while((atual=bfs())){
            flow+=atual;
            int u=t;
            vector<int> agr;
            while(u!=s){
                int prev=pai[u].f, edge=pai[u].s;
                ll agr=atual;
                if(edge&1) agr*=-1, edge--;
                cap[edge]-=agr, cap[edge+1]+=agr;
                u=prev; 
            }
        }
        return flow;
    }
};
