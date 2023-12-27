int memo[mxn], par[mxn];

bool dfs(int x){
    if(memo[x]) return 0;
    memo[x]=1;
    for(int i:vec[x]){
        if(!par[i] || dfs(par[i])){
            par[i]=x;
            return 1;
        }
    }
    return 0;
}
void kuhn(){
    int resp=0;
    for(int i=1; i<=n; i++){
        for(int j:vec[i]){
            if(!par[j]){
                par[j]=i;
                temp[i]=1;
                resp++;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(temp[i]) continue;
        memset(memo, 0, sizeof(memo));
        if(dfs(i)) resp++;
    }
    cout << resp << endl;
    for(int i=1; i<=m; i++){
        if(par[i]){
            cout << par[i] << " " << i << endl;
        }
    }
}
