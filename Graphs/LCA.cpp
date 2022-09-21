void dfs(int x, int p){
    for(int i:viz[x]){
        if(i==p) continue;
        nivel[i]=nivel[x]+1;
        anc[i][0]=x;
        dfs(i, x);
    }
}

int lca(int a, int b){
    if(nivel[a]<nivel[b]){
        swap(a, b);
    }
    for(int i=18; i>=0; i--){
        if(nivel[a]-(1<<i)>=nivel[b]){
            a=anc[a][i];
        }
    }
    if(a==b) return a;
    for(int i=18; i>=0; i--){
        if(anc[a][i]!=-1 && anc[a][i]!=anc[b][i]){
            a=anc[a][i];
            b=anc[b][i];
        }
    }
    return anc[a][0];
}

for(int j=1; j<=18; j++){
    for(int i=1; i<=n; i++){
        if(anc[i][j-1]!=-1){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}
