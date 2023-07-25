pair<int, vector<int> > hung(const vector<vector<int> > &a){
    int n = (int)a.size() + 1, m = (int)a[0].size() + 1;

    vector<int> u(n), v(m), p(m), ans(n-1);

    for(int i=1; i<n; i++){
        p[0] = i;
        int j0 = 0;
        vector<int> dist(m, INF), pre(m, -1);
        vector<bool> done(m + 1);

        do{ 
            done[j0]=true;
            int i0=p[j0], j1, delta=INF;

            for(int j=1; j<m; j++){
                if(!done[j]){
                    auto cur = a[i0-1][j-1] - u[i0] - v[j];

                    if(cur<dist[j]) dist[j]=cur, pre[j]=j0;
                    
                    if(dist[j]<delta) delta=dist[j], j1=j;
                }
            }
            for(int j=0; j<m; j++){
                if(done[j]) u[p[j]]+=delta, v[j]-=delta;
                else dist[j]-=delta;
            }
            j0=j1;
        }while(p[j0]);

        while(j0){
            int j1=pre[j0];
            p[j0]=p[j1], j0=j1;
        }
    }
    for(int j=1; j<m; j++) if(p[j]) ans[p[j]-1]=j-1;
    return {-v[0], ans};
}
