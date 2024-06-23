// O(N*M)
//1 - indexed
vector<int> vec[mxn];
int memo[mxn], pai[mxn], filho[mxn], temp[mxn];

bool dfs(int x){
    if(memo[x]) return 0;
    memo[x]=1;
    for(int i:vec[x]){
        if(!pai[i] || dfs(pai[i])){
            pai[i]=x, filho[x]=i;
            return 1;
        }
    }
    return 0;
}
pair<int, vector<pair<int, int> > > kuhn(){
    int resp=0;
    for(int i=1; i<=n; i++){
        for(int j:vec[i]){
            if(!pai[j]){
                pai[j]=i, filho[i]=j, temp[i]=1, resp++;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(temp[i]) continue;
        memset(memo, 0, sizeof(memo));
        if(dfs(i)) resp++;
    }
    vector<pair<int, int> > ans;
    for(int i=1; i<=n; i++){
        if(filho[i]) ans.push_back({i, filho[i]});
    }
    return {resp, ans};
}