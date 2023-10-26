int tempo[mxn], lv[mxn];
vector<int> vec[mxn], path, walk;

//sparse table of min on walk, with n as n-1

void dfs(int x, int p){
    tempo[x]=t++;
    for(int i:vec[x]){
        if(i==p) continue;
        path.push_back(x);
        walk.push_back(tempo[x]);
        lv[i]=lv[x]+1;
        dfs(i, x);
    }
}

int lca(int a, int b){
    if(a==b) return a;
    tie(a, b) = minmax(tempo[a], tempo[b]);
    return path[query(a, b)];
}

int dist(int a, int b){
    return lv[a]+lv[b]-2*lv[lca(a, b)];
}
