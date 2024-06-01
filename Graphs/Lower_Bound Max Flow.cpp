struct LB_flow{
    int n;
    vector<ll> d;
    Dinic dinic;
 
    LB_flow(int n) : n(n), dinic(n+2), d(n) {}

    void add_edge(int a, int b, ll l, ll c){
        d[a]-=l, d[b]+=l;
        dinic.add_edge(a, b, c-l);
    }

    bool has_flow(int s, int t){
        dinic.add_edge(t, s, INFL);
        ll sum = 0;
        for(int i=0; i<n; i++){
            if(d[i]>0){
                sum+=d[i];
                dinic.add_edge(n, i, d[i]);
            }else{
                dinic.add_edge(i, n+1, -d[i]);
            }
        }
        return (sum == dinic.max_flow(n, n+1));
    }

    ll max_flow(int s, int t){
        if(!has_flow(s, t)) return -1;
        return dinic.max_flow(s, t);
    }
};