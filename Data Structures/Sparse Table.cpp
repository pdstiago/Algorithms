void build() {
    for(int i=1; i<=n; i++) tab[i][0]=v[i];
    for(int j=1; j<=18; j++){
        for(int i=1; i<=n; i++){
            if(i + (1<<j)-1 > n) break;
            tab[i][j]=min(tab[i][j-1], tab[i+(1<<(j-1))][j-1]);
        }
    }
}

int flog(int x){
    return 31 - __builtin_clz(x);
}

int flog(long long x){
    return 63 - __builtin_clzll(x);
}

int queryminmax(int l, int r){
    int k = flog(r-l+1);
    return min(tab[l][k], tab[r-(1<<k)+1][k]);
}

int querysum(int l, int r){
    int ans=0;
    for(int i=10; i>=0; i--){
        if(l + (1<<i) - 1 <= r){
            ans+=tab[l][i];
            l+=(1<<i);
        }
    }
    return ans;
}
