void upd(int x, int val){
    while(x<=n){
        bit[x]+=val;
        x+=x&-x;
    }
}
 
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=bit[x];
        x-=x&-x;
    }
    return ans;
}
