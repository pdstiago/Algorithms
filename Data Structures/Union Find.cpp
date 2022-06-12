int pai[mxn], peso[mxn];

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

int main(){
    fastio;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        pai[i]=i;
    }
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        total.pb({c, {a, b}});
    }
    sort(all(total));
    for(pip i:total){
        if(ff(i.s.f)!=ff(i.s.s)){
            uu(i.s.f, i.s.s);
            resp+=i.f;
        }
    }
    cout << resp;
    return 0;
}
