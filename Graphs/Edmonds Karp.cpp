struct Karp{ // Karp karp(n, m, 1, n); O(VE²)
    int n, m=0, s, t;
    vector<vector<pii> > vec;
    vector<ll> cap;
    vector<pii> pai;

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

    ll bfs(){
        fill(pai.begin(), pai.end(), make_pair(-1,-1));
        pai[s]={0, 0};

        queue<pair<int, ll> > fila;
        fila.push({s, INFL});

        while(!fila.empty()){
            int v=fila.front().f;
            ll atual=fila.front().s;
            fila.pop();

            for(pii i:vec[v]){
                if(pai[i.f].f==-1 && cap[i.s]){
                    pai[i.f]={v, i.s};
                    ll flow=min(atual, cap[i.s]);
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
                cap[edge]-=atual;
                cap[edge^1]+=atual;
                u=prev; 
            }
        }
        return flow;
    }
};