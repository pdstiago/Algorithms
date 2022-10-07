void dj(){
    memset(dist, INF, sizeof(dist));
    memset(memo, 0, sizeof(memo));
    dist[1]=0;
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push({0, 1});
    while(!fila.empty()){
        pii u=fila.top();
        fila.pop();
        if(memo[u.s]) continue;
        memo[u.s]=1;
        for(pii i:vec[u.s]){
            if(dist[i.f]>dist[u.s]+i.s){
                dist[i.f]=dist[u.s]+i.s;
                fila.push({dist[i.f], i.f});
            }
        }
    }
}
