struct Euler{ // Euler euler(n, m, 0); O(V+E)
    int n, m, cont=0, dir;
    vector<vector<pii> > vec;
    vector<int> grau, in, out, id;

    Euler(int n, int m, int dir) : n(n), m(m), dir(dir){
        vec.resize(n+1);
        grau.resize(n+1);
        id.resize(m);
        in.resize(n+1);
        out.resize(n+1);
    }

    void add_edge(int v, int u){
        vec[v].pb({u, cont});
        grau[v]++, out[v]++, in[u]++;
        if(!dir){
            vec[u].pb({v, cont});
            grau[u]++;
        }
        cont++;
    }

    int check_circuit(){
        if(!dir){
            for(int i=1; i<=n; i++){
                if(grau[i]&1) return 0;
            }
            return 1;
        }
        for(int i=1; i<=n; i++){
            if(in[i]!=out[i]) return 0;
        }
        return 1;
    }

    int check_path(){
        if(!dir){
            int impar=0;
            for(int i=1; i<=n; i++){
                impar+=(grau[i]&1);
            }
            if(!impar || impar==2) return 1;
            return 0;
        }
        int maior=0, menor=0;
        for(int i=1; i<=n; i++){
            if(out[i]-in[i]==1){
                if(maior) return 0;
                maior++;
            }
            else if(in[i]-out[i]==1){
                if(menor) return 0;
                menor++;
            }else if(in[i]!=out[i]){
                return 0;
            }
        }
        return 1;
    }

    vector<int> find_euler(){
        vector<int> fila, ans;
        //check the initial and final vertices
        fila.pb(1);
        while(!fila.empty()){
            int v=fila.back();
            while(!vec[v].empty() && id[vec[v].back().s]){
                grau[v]--;
                vec[v].pop_back();
            }
            if(!grau[v]){
                ans.pb(v);
                fila.pop_back();
                continue;
            }
            pii u=vec[v].back();
            vec[v].pop_back();
            grau[v]--;
            id[u.s]=1;
            fila.pb(u.f);
        }
        reverse(all(ans));
        if(sz(ans)!=m+1) ans.clear();
        return ans;
    }
};
