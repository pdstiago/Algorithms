/*
Créditos: Caderno da UFMG
art[i] possui o número de novas componentes conexas
criadas após a remoção de i do grafo g

blocks[i] possui todos os vértices daquele bloco, incluindo o ponto de articulação
edgblocks[i] são as arestas do bloco i
bct[i] é o vértice da árvore que corresponde ao bloco i

pos[i] indica qual vértice da árvore, o vértice i pertence

A árvore tem no máximo 2n vértices
*/
struct BCT{ // O(N+M)
    int n, t;
    vector<vector<int> > g, blocks, bct;
    vector<vector<pair<int, int> > > edgblocks;
    stack<int> s;
    stack<pair<int, int> > s2;
    vector<int> id, art, pos;
    
    BCT(const vector<vector<int> > &g) : n((int)g.size()), g(g), id(n, -1), art(n), pos(n){
        build();
    }

    int dfs(int i, int p=-1){
        int lo = id[i] = t++;
        s.push(i);	
        
        if(p!=-1) s2.emplace(i, p);
        for(int j:g[i]) if(j!=p && id[j]!=-1) s2.emplace(i, j);
        
        for(int j:g[i]){
            if(j==p) continue;
            if(id[j]==-1){
                int val=dfs(j, i);
                lo=min(lo, val);

                if(val>=id[i]){
                    art[i]++;
                    blocks.emplace_back(1, i);
                    while(blocks.back().back()!=j) blocks.back().push_back(s.top()), s.pop();
                    edgblocks.emplace_back(1, s2.top()), s2.pop();
                    while(edgblocks.back().back()!=pair(j, i)) edgblocks.back().push_back(s2.top()), s2.pop();
                }
                //if(val>id[i]) aresta i-j é ponte
            }
            else lo=min(lo, id[j]);
        }
        if(p==-1 && art[i]) art[i]--;
        return lo;
    }

    void build(){
        t=0;
        for(int i=0; i<n; i++) if(id[i]==-1) dfs(i, -1);
        
        bct.resize(blocks.size());
        for(int i=0; i<n; i++) if(art[i]) pos[i]=bct.size(), bct.emplace_back();

        for(int i=0; i<(int)blocks.size(); i++){
            for(int j:blocks[i]){
                if(!art[j]) pos[j]=i;
                else bct[i].push_back(pos[j]), bct[pos[j]].push_back(i);
            }
        }
    }
};
