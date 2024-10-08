// O(N^2 * M)
// para matching máximo, multiplicar os pesos por -1
// o valor na posição i do vector retornado indica a coluna do elemento da linha i que foi escolhido
template<typename T>
pair<T, vector<int> > hung(const vector<vector<T> > &a){
    if(a.empty()) return {0, {}};

    int n=(int)a.size()+1, m=(int)a[0].size()+1;

    vector<int> p(m), ans(n-1);
    vector<T> u(n), v(m);

    for(int i=1; i<n; i++){
        p[0]=i;
        int j0=0;
        vector<T> dist(m, INF); //remember to change
        vector<int> pre(m, -1);
        vector<bool> done(m+1);

        do{ 
            done[j0]=true;
            int i0=p[j0], j1;
            T delta=INF; //remember to change

            for(int j=1; j<m; j++){
                if(!done[j]){
                    auto cur=a[i0-1][j-1]-u[i0]-v[j];

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