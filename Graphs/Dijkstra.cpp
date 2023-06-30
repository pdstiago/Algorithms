void dj(int x){
    memset(dist, INF, sizeof(dist));
    memset(memo, 0, sizeof(memo));
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
    dist[x]=0;
    fila.push({0, x});
    while(!fila.empty()){
        int u=fila.top().second;
        fila.pop();
        if(memo[u]) continue;
        memo[u]=1;
        for(pair<int, int> i:vec[u]){
            if(dist[i.first]>dist[u]+i.second){
                dist[i.first]=dist[u]+i.second;
                fila.push({dist[i.first], i.first});
            }
        }
    }
}
