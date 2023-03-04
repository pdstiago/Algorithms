void dfs(int x){
    memo[x]=1;
    for(int i:vec[x]){
        if(!memo[i]) dfs(i);
    }
    st.pb(x);
}
void dfs2(int x){
    memo[x]=0;
    for(int i:vec2[x]){
        if(memo[i]) dfs2(i);
    }
    st2.pb(x);
}
void kosaraju(){
    int comp=0;
    for(int i=1; i<=n; i++){
        if(!memo[i]) dfs(i);
    }
    for(int i=n-1; i>=0; i--){
        if(memo[st[i]]){
            dfs2(st[i]);
            comp++;
        }
    }
}
