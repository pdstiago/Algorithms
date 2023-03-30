void dfs(int x){
    memo[x]=1;
    for(int i:vec[x]){
        if(!memo[i]) dfs(i);
    }
    order.pb(x);
}
void dfs2(int x){
    memo[x]=0;
    for(int i:rvec[x]){
        if(memo[i]) dfs2(i);
    }
}
void scc(){
    int comp=0;
    for(int i=1; i<=n; i++){
        if(!memo[i]) dfs(i);
    }
    reverse(order.begin(), order.end());
    for(int i:order){
        if(memo[i]){
            dfs2(i);
            comp++;
        }
    }
}
