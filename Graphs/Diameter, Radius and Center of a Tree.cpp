void dfs(int x, int p){
    for(int i:vec[x]){
        if(i==p) continue;
        dist[i]=dist[x]+1;
        dfs(i, x);
    }
}
void tree(){
    int p1, p2, centro, diam=-1, raio=INF;
    dfs(1, 0);
    for(int i=1; i<=n; i++){
        if(dist[i]>diam){
            diam=dist[i];
            p1=i;
        }
    }
    memset(dist, 0, sizeof(dist));
    dfs(p1, 0);
    for(int i=1; i<=n; i++) exc[i]=dist[i];
    diam=-1;
    for(int i=1; i<=n; i++){
        if(dist[i]>diam){
            diam=dist[i];
            p2=i;
        }
    }
    memset(dist, 0, sizeof(dist));
    dfs(p2, 0);
    for(int i=1; i<=n; i++) exc[i]=max(exc[i], dist[i]);
    for(int i=1; i<=n; i++){
        if(exc[i]<raio) raio=exc[i], centro=i;
    }
}
