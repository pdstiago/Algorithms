void dj(int x){
    for(int i=1; i<=n; i++) dist[i]=INF;
    priority_queue<pair<int, int> > fila;
    dist[x]=0;
    fila.push({0, x});
    while(!fila.empty()){
        int d = -fila.top().first, u = fila.top().second;
        fila.pop();
        if(d>dist[u]) continue;
        for(pair<int, int> i:vec[u]){
            if(dist[i.first]>dist[u]+i.second){
                dist[i.first]=dist[u]+i.second;
                fila.push({-dist[i.first], i.first});
            }
        }
    }
}
