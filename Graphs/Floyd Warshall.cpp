void construct(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j]=INF;
            if(i==j) dist[i][j]=0;
        }
    }   
}
void input(){
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b]=min(dist[a][b], c);
        dist[b][a]=min(dist[b][a], c);
    }   
}
void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j]=min(dist[i][j], 
                dist[i][k]+dist[k][j]);
            }
        }
    }   
}
