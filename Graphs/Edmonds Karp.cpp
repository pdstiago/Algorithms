ll bfs(int s, int t){
    memset(pai, 0, sizeof(pai));
    
    queue<pii> fila;
    fila.push({s, INFL});

    while(!fila.empty()){
        pii atual=fila.front();
        fila.pop();

        for(pii i:vec[atual.f]){
            if(!pai[i.f].f && cap[i.s]){
                pai[i.f]={atual.f, i.s};

                ll flow=min(atual.s, cap[i.s]);

                if(i.f==t) return flow;

                fila.push({i.f, flow});
            }
        }
    }
    return 0;
}
ll karp(int s, int t){
    ll flow=0, novo;
    while(novo=bfs(s, t)){
        flow+=novo;
        int u=t;
        while(u!=s){
            int prev=pai[u].f, edge=pai[u].s;

            ll atual=novo;

            if(edge&1) atual*=-1, edge--;

            cap[edge]-=atual, cap[edge+1]+=atual;

            u=prev; 
        }
    }
    return flow;
}
void input(){
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].pb({b, 2*i});
        vec[b].pb({a, 2*i+1});
        cap[2*i]=c;
        cap[2*i+1]=0;
    }
}
