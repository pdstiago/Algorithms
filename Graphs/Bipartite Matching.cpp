bool bm(int x){
    for(int i:vec[x]){
        if(!memo[i]){
            memo[i]=1;
            if(!got[i] || bm(got[i])){
                got[i]=x;
                return true;
            }
        }
    }
    return false;
}

for(int i=1; i<=n; i++){
    memset(memo, 0, sizeof(memo));
    if(bm(i)){
        ans++;
    }
}
