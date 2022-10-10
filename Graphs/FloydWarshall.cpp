for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
        if(i==j){
            dist[i][j]=0;
            continue;
        }
        dist[i][j]=INFL;
    }
}
for(int i=1; i<=m; i++){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    dist[a][b]=min(dist[a][b], c);
    dist[b][a]=min(dist[b][a], c);
}
for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
        }
    }
}
