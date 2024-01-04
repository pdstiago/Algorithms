struct Euler{ // Euler euler(n, m, 0); O(V+E)
    int n, m, cont=0, dir;
    //dir==0, grafo não direcionado / dir==1, grafo direcionado
    vector<vector<pair<int, int> > > vec;
    vector<int> grau, in, out, id;

    Euler(int n, int m, int dir) : n(n), m(m), dir(dir), vec(n+1), grau(n+1), id(m), in(n+1), out(n+1) {}

    void add_edge(int v, int u){
        vec[v].push_back({u, cont});
        grau[v]++, out[v]++, in[u]++;
        if(!dir){
            vec[u].push_back({v, cont});
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
        fila.push_back(1); //check initial vertice
        while(!fila.empty()){
            int v=fila.back();
            while(!vec[v].empty() && id[vec[v].back().second]){
                grau[v]--;
                vec[v].pop_back();
            }
            if(!grau[v]){
                ans.push_back(v);
                fila.pop_back();
                continue;
            }
            pair<int, int> u=vec[v].back();
            vec[v].pop_back();
            grau[v]--;
            id[u.second]=1;
            fila.push_back(u.first);
        }
        reverse(ans.begin(), ans.end());

        //if empty vector is returned is impossible
        if((int)ans.size()!=m+1) ans.clear();
        if(ans[m]!=1) ans.clear() //check final vertice

        return ans;
    }
};
