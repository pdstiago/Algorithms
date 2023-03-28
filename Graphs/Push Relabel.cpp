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
vector<int> find_v(int s, int t){
    vector<int> max_h;
    for(int i=1; i<=n; i++){
        if(i!=s && i!=t && ex[i]){
            if(!max_h.empty() && lv[i]>lv[max_h[0]]){
                max_h.clear();
            }
            if(max_h.empty() || lv[i]==lv[max_h[0]]){
                max_h.pb(i);
            }
        }
    }
    return max_h;
}
ll push_relabel(int s, int t){ // O(VE+V^2*sqrt(E)), worst case O(V^3)
    lv[s]=n;
    ex[s]=INFL;
    for(int i=1; i<=n; i++){
        if(i!=s) push(s, i);
    }
    vector<int> atual;
    while(!(atual=find_v(s, t)).empty()){
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
    ll max_flow=0;
    for(int i=1; i<=n; i++){
        max_flow+=flow[i][t];
    }
    return max_flow;
}
void input(){
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cap[a][b]+=c;
    }
}
