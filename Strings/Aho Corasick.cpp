const int sigma = 26;
struct Aho{
    int n;
    array<int, sigma> init;
    vector<array<int, sigma> > trie;
    vector<int> out, parent, ids, bfs, f;
    vector<string> v;

    Aho(vector<string> &v) : n((int)v.size()), v(v), out(1, -1), parent(n, -1), ids(n) {
        for(int i=0; i<sigma; i++) init[i] = -1;
        trie.push_back(init);

        for(int i=0; i<n; i++){
            int cur = 0;
            for(char ch:v[i]){
                int c = ch - 'a';
                if(trie[cur][c]==-1){
                    trie[cur][c] = (int)trie.size();
                    trie.push_back(init); out.push_back(-1);
                }
                cur = trie[cur][c];
            }
            if(out[cur]==-1) out[cur] = i;
            ids[i] = out[cur];
        }

        f.resize(trie.size());
        bfs.reserve(trie.size());

        for(int c=0; c<sigma; c++){
            if(trie[0][c]==-1) trie[0][c] = 0;
            else bfs.push_back(trie[0][c]);
        }
        for(int z=0; z<(int)bfs.size(); z++){
            int cur = bfs[z];
            for(int c=0; c<sigma; c++){
                if(trie[cur][c]==-1)
                    trie[cur][c] = trie[f[cur]][c];
                else{
                    int nxt = trie[cur][c];
                    int fail = trie[f[cur]][c];
                    if(out[nxt]==-1) out[nxt] = out[fail];
                    else parent[out[nxt]] = out[fail];
                    f[nxt] = fail; bfs.push_back(nxt);
                }
            }
        }
    }

    void run_pos(string &ss){
        int state = 0, pos = 0;
        for(char ch:ss){
            int c = ch - 'a';
            state = trie[state][c];
            int i = out[state];
            while(i!=-1){
                // ocorrência da string i na posição pos
                i = parent[i];
            }
            pos++;
        }
    }

    void run_count(string &ss){
        int state = 0;
        vector<int> freq(n), freqNode(trie.size());
        for(char ch:ss){
            int c = ch - 'a';
            state = trie[state][c];
            freqNode[state]++;
        }
        for(int i=(int)bfs.size()-1; i>=0; i--){
            int cur = bfs[i];
            int pcur = f[cur];
            freqNode[pcur]+=freqNode[cur];
            if(out[cur]!=-1){
                freq[out[cur]] = freqNode[cur];
            }
        }
        // freq possui a frequência de cada string na string ss
    }
};