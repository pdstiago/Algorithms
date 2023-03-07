void dfs(int x, int p){
    for(int j=1; j<=18; j++){
        if(anc[x][j-1]!=-1){
            anc[x][j]=anc[anc[x][j-1]][j-1];
        }
    }
    for(int i:vec[x]){
        if(i==p) continue;
        lv[i]=lv[x]+1;
        anc[i][0]=x;
        dfs(i, x);
    }
}
pii lca(int a, int b){
    if(lv[a]<lv[b]) swap(a, b);
    int dist=0;
    for(int i=18; i>=0; i--){
        if(lv[a]-(1<<i)>=lv[b]){
            dist+=(1<<i);
            a=anc[a][i];
        }
    }
    if(a==b) return {a, dist};
    for(int i=18; i>=0; i--){
        if(anc[a][i]!=-1 && anc[a][i]!=anc[b][i]){
            a=anc[a][i], b=anc[b][i];
            dist+=2*(1<<i);
        }
    }
    dist+=2;
    return {anc[a][0], dist};
}
