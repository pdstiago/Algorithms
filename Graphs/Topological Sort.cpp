void top_sort(){
    queue<int> fila;
    for(int i=1; i<=n; i++){
        if(!grau[i]) fila.push(i);
    }
    while(!fila.empty()){
        int u=fila.front();
        resp.pb(u);
        fila.pop();
        for(int i:vec[u]){
            grau[i]--;
            if(!grau[i]) fila.push(i);
        }
    }
    if(sz(resp)<n) cout << "IMPOSSIBLE" << endl;
}
