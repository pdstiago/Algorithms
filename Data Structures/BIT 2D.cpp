void upd(int x, int y, int val){
    for(; x<=n; x+=x&-x){
        for(int j=y; j<=n; j+=j&-j){
            bit[x][j]+=val;
        }
    }
}

int sum(int x, int y){
    int ans=0;
    for(; x; x-=x&-x){
        for(int j=y; j>0; j-=j&-j){
            ans+=bit[x][j];
        }
    }
    return ans;
}

int query(int a, int b, int c, int d){
    return sum(c, d)-sum(a-1, d)-sum(c, b-1)+sum(a-1, b-1);
}
