int pai[mxn], peso[mxn];

int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[y]>peso[x]) swap(x, y);
    pai[y]=x;
    peso[x]+=peso[y];
}

void build(){
    for(int i=1; i<=n; i++){
        pai[i]=i;
        peso[i]=1;
    }
}