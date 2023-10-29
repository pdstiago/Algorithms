int memo[mxn], tin[mxn], low[mxn], artic[mxn], cont;
vector<int> bridges;

void dfs(int x, int p){
    memo[x]=1;
    tin[x]=low[x]=++cont;
    int children=0;
    for(int i:vec[x]){
        if(i==p) continue;
        if(memo[i]){
            low[x]=min(low[x], tin[i]);
        }else{
            dfs(i, x);
            low[x]=min(low[x], low[i]);
            if(low[i]>tin[x]){
                bridges.push_back({min(i, x), max(i, x)});
            }
            if(low[i]>=tin[x] && p) artic[x]=1;
            children++;
        }
    }
    if(!p && children>1) artic[x]=1;
}

void build(){
    cont=0;
    bridges.clear();
    for(int i=1; i<=n; i++){
        memo[i]=low[i]=tin[i]=artic[i]=0;
    }
    for(int i=1; i<=n; i++){
        if(!memo[i]){
            dfs(i, 0);
        }
    }
}
