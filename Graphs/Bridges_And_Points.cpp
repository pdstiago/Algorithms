void dfs(int x, int p){
    memo[x]=1;
    tin[x]=low[x]=++cont;
    int children=0;
    for(int i:vec[x]){
        if(i==p) continue;
        if(memo[i]){
            low[x]=min(low[x], tin[i]);
        }else{
            dfs(i, x);
            low[x]=min(low[x], low[i]);
            if(low[i]>tin[x]){
                bridges.pb({min(i, x), max(i, x)});
            }
            if(low[i]>=tin[x] && p!=-1) artic[x]=1;
            children++;
        }
    }
    if(p==-1 && children>1) artic[x]=1;
}

void find_bridges_and_points(){
    cont=0;
    bridges.clear();
    for(int i=1; i<=n; i++){
        memo[i]=low[i]=tin[i]=artic[i]=0;
    }
    for(int i=1; i<=n; i++){
        if(!memo[i]){
            dfs(i, 0);
        }
    }
    cout << endl << "Points: " << endl;
    for(int i=1; i<=n; i++){
        cout << artic[i] << es;
    }
    cout << endl << endl << "Bridges: " << endl;
    sort(all(bridges));
    for(pii i:bridges){
        cout << i.f << es << i.s << endl;
    }
    cout << endl;
}
