int dfs_sz(int x, int p=0){
    sub[x]=1;
    for(int i:vec[x]){
        if(i==p || used[i]) continue;
        sub[x]+=dfs_sz(i, x);
    }
    return sub[x];
}
int find_c(int x, int total, int p=0){
    for(int i:vec[x]){
        if(i==p || used[i]) continue;
        if(2*sub[i]>total) return find_c(i, total, x);
    }
    return x;
}
void build(int x=1, int p=0){
    int c=find_c(x, dfs_sz(x));
    used[c]=1;
    pai[c]=p;
    for(int i:vec[c]){
        if(!used[i]) build(i, c);
    }
}
