int ff(int x){
    if(pai[x]==x) return x;
    return pai[x]=ff(pai[x]);
}

void uu(int x, int y){
    x=ff(x), y=ff(y);
    if(x==y) return;
    if(peso[x]>=peso[y]){
        pai[y]=x;
        peso[x]++;
    }else{
        pai[x]=y;
        peso[y]++;
    }
}
