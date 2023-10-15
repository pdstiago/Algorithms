int sub[mxn], tour[mxn], tin[mxn], tout[mxn], lv[mxn], cont[mxn], timer;

// dfs(1, 0) / large(1, 0, 1)

void dfs(int x, int p){
    sub[x]=1;
    tour[timer]=x;
    tin[x]=timer++;
    for(int i:vec[x]){
        if(i==p) continue;
        lv[i]=lv[x]+1;
        dfs(i, x);
        sub[x]+=sub[i];
    }
    tout[x]=timer;
}

void large(int x, int p, bool ok){
    int mx=-1, big=-1;
    for(int i:vec[x]){
        if(i!=p && sub[i]>mx){
            mx=sub[i], big=i;
        }
    }
    for(int i:vec[x]){
        if(i!=p && i!=big){
            large(i, x, 0);
        }
    }
    if(big!=-1){
        large(big, x, 1);
    }
    //realiza a operação para o vertice atual
    cont[color[x]]++;
    for(int i:vec[x]){
        if(i!=p && i!=big){
            for(int j=tin[i]; j<tout[i]; j++){
                int u=tour[j];
                cont[color[u]]++;
            }
        }
    }
    //cont[v] possui a quantidade de vertices da cor v na subarvore de x
    
    // faço o inverso da operação
    if(!ok){
        for(int i=tin[x]; i<tout[x]; i++){
            int u=tour[i];
            cont[color[u]]--;
        }
    }
}
