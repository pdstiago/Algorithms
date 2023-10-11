void upd(int x, int val){
    for(; x<=n; x+=x&-x) bit[x]+=val;
}

int sum(int x){
    int ans=0;
    for(; x; x-=x&-x) ans+=bit[x];
    return ans;
}

int busca(int val){
    int sum=0, pos=0;
    for(int i=18; i>=0; i--){
        int newpos = pos+(1<<i);
        if(newpos<n && sum+bit[newpos]<val){
            sum+=bit[newpos];
            pos=newpos;
        }
    }
    return pos+1;
}
