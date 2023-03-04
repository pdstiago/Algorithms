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
void sat(){
    for(int i=1; i<=n; i++){
        int a, b, c1, c2;
        char sa, sb;
        cin >> sa >> a >> sb >> b;
        // (+ 2 - 1) quero topping 2, mas nn quero o 1
        // f = (x1 ou y1) e ... (xn ou yn), se f == 1, então é possível
        // (x1 ou y1) = x1 -> ~y1 = y1 -> ~x1
        // se x1 e ~x1 estiverem na mesma scc é impossível
        if(sa=='+') c1=0;
        if(sa=='-') c1=m;
    
        if(sb=='+') c2=m;
        if(sb=='-') c2=0;
    
        vec[a+c1].pb(b+c2);
        vec2[b+c2].pb(a+c1);
    
        if(sa=='+') c1=m;
        if(sa=='-') c1=0;
    
        if(sb=='+') c2=0;
        if(sb=='-') c2=m;
    
        vec[b+c2].pb(a+c1);
        vec2[a+c1].pb(b+c2);
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
    char resp[mxn];
    
    for(int i=1; i<=m; i++){
        if(comp[i]==comp[i+m]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        resp[i]=comp[i]>comp[i+m]?'-':'+';
    }
}
