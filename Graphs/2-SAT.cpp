void dfs(int x){
    memo[x]=1;
    for(int i:vec[x]){
        if(!memo[i]) dfs(i);
    }
    st.pb(x);
}
void dfs2(int x, int c){
    comp[x]=c;
    for(int i:vec2[x]){
        if(!comp[i]) dfs2(i, c);
    }
}
void add(int x, int sx, int y, int sy){
    sx^=1, sy^=1;
    
    vec[x+m*sx].pb(y+m*(!sy));
    vec[y+m*sy].pb(x+m*(!sx));
 
    vec2[y+m*(!sy)].pb(x+m*sx);
    vec2[x+m*(!sx)].pb(y+m*sy);
}
int sat(){
    for(int i=1; i<=n; i++){
        int a, b, c1, c2;
        char sa, sb;
        cin >> sa >> a >> sb >> b;
        // (+ 2 - 1) quero topping 2, mas nn quero o 1
        // f = (x1 ou y1) e ... (xn ou yn), se f == 1, então é possível
        // (x1 ou y1) = x1 -> ~y1 = y1 -> ~x1
        // se x1 e ~x1 estiverem na mesma scc é impossível
        c1=(sa=='+'?1:0);
        c2=(sb=='+'?1:0);
    
        add(a, c1, b, c2);
    }
    for(int i=1; i<=2*m; i++){
        if(!memo[i]) dfs(i);
    }
    int cont=0;
    for(int i=2*m-1; i>=0; i--){
        if(!comp[st[i]]){
            dfs2(st[i], ++cont);
        }
    }
    for(int i=1; i<=m; i++){
        if(comp[i]==comp[i+m]) return 0;
        resp[i]=comp[i]>comp[i+m]?'-':'+';
    }
    return 1;
}
