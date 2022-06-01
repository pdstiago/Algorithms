void dj(){
    memset(dist, INF, sizeof(dist));
    dist[1]=0;
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push({0, 1});
    while(!fila.empty()){
        pii pri=fila.top();
        fila.pop();
        for(pii i:vec[pri.s]){
            int v=i.f;
            int c=i.s;
            if(dist[v]>dist[pri.s]+c){
                dist[v]=dist[pri.s]+c;
                fila.push({dist[v], v});
            }
        }
    }
}
