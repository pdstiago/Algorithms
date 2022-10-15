for(int i=1; i<=m; i++){
    int a, b;
    cin >> a >> b;
    grau[b]++;
    vec[a].pb(b);
}
vector<int> resp;
queue<int> fila;
for(int i=1; i<=n; i++){
    if(!grau[i]){
        fila.push(i);
    }
}
while(!fila.empty()){
    int u=fila.front();
    resp.pb(u);
    fila.pop();
    for(int i:vec[u]){
        grau[i]--;
        if(!grau[i]){
            fila.push(i);
        }
    }
}
for(int i:resp){
    cout << i << es;
}
