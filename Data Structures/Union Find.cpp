struct DSU{
    vector<int> pai, peso;
    DSU(int n) : pai(n+1), peso(n+1) {
        for(int i=1; i<=n; i++){
            pai[i] = i;
            peso[i] = 1;
        }
    }
    int ff(int x){
        if(pai[x]==x) return x;
        return pai[x]=ff(pai[x]);
    }
    int uu(int x, int y){
        x=ff(x), y=ff(y);
        if(x==y) return 0;
        if(peso[y]>peso[x]) swap(x, y);
        pai[y]=x;
        peso[x]+=peso[y];
        return 1;
    }
};