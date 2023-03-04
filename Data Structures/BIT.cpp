void upd(int x, int val){
    for(; x<=n; x+=x&-x) bit[x]+=val;
}

int sum(int x){
    int ans=0;
    for(; x; x-=x&-x) ans+=bit[x];
    return ans;
}
