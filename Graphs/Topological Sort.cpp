vector<int> top_sort(){
    vector<int> resp;
    queue<int> fila;
    for(int i=1; i<=n; i++){
        if(!grau[i]) fila.push(i);
    }
    while(!fila.empty()){
        int u=fila.front();
        resp.push_back(u);
        fila.pop();
        for(int i:vec[u]){
            grau[i]--;
            if(!grau[i]) fila.push(i);
        }
    }
    if((int)resp.size()<n){
        return {};
    }else{
        return resp;
    }
}
