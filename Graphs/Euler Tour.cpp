int euler(){
    //vector<pii> vec[mxn];
    //vec.f = vizinho, vec.s=id da aresta
    for(int i=1; i<=n; i++){
        if(grau[i]&1) return 0;
    }
    vector<int> fila;
    fila.pb(1);
    while(!fila.empty()){
        int v=fila.back();
        while(!vec[v].empty() && id[vec[v].back().s]){
            grau[v]--;
            vec[v].pop_back();
        }
        if(!grau[v]){
            ans.pb(v);
            fila.pop_back();
            continue;
        }
        pii u=vec[v].back();
        vec[v].pop_back();
        grau[v]--;
        id[u.s]=1;
        fila.pb(u.f);
    }
    if(sz(ans)!=m+1) return 0;
    reverse(all(ans));
    return 1;
}
