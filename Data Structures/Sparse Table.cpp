void build(){ //0-indexed
    for(int i=0; i<n; i++) tab[i][0]=v[i];
    for(int j=1; j<=18; j++){
        for(int i=0; i<n; i++){
            if(i+(1<<(j-1)) >= n) break;
            tab[i][j]=min(tab[i][j-1], tab[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l, int r){ //[l, r)
    int k = __lg(r-l);
    return min(tab[l][k], tab[r-(1<<k)][k]);
}

int query(int l, int r){ //[l, r)
    int ans=0;
    for(int i=18; i>=0; i--){
        if(l + (1<<i) <= r){
            ans+=tab[l][i];
            l+=(1<<i);
        }
    }
    return ans;
}
