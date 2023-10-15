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

int query(int x1, int y1, int x2, int y2){
    return sum(x2, y2)-sum(x1-1, y2)-sum(x2, y1-1)+sum(x1-1, y1-1);
}
