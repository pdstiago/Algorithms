void dfs(int x, int p){
    for(int i:vec[x]){
        if(i==p) continue;
        pai[i]=x;
        dist[i]=dist[x]+1;
        dfs(i, x);
    }
}
void tree(){
    int maior=0, p1, p2, diam, raio, centro, atual;
    dfs(1, 0);
    for(int i=1; i<=n; i++){
        if(dist[i]>maior){
            maior=dist[i];
            p1=i;
        }
    }
    dfs(p1, 0);
    maior=0;
    for(int i=1; i<=n; i++){
        if(dist[i]>maior){
            maior=dist[i];
            p2=i;
        }
    }
    diam=maior;
    raio=(diam+1)/2;
    atual=p2;
    while(dist[atual]>diam/2){
        atual=pai[atual];
    }
    centro=atual;
}
