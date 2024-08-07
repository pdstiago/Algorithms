template <class T> struct HLD{
    int n, cont=0;
    vector<int> sub, pai, heavy, chain, pos;
    vector<T> v;
    vector<vector<int> > vec;
    Seg<T> seg;

    HLD(int n) : n(n), seg(n), sub(n+1), pai(n+1), heavy(n+1), chain(n+1), pos(n+1), vec(n+1), v(n+1) {}

    void add_edge(int a, int b){
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    void dfs(int x, int p){
        sub[x]=1;
        int maior=0;
        for(int i:vec[x]){
            if(i==p) continue;
            dfs(i, x);
            if(sub[i]>maior) maior=sub[i], heavy[x]=i;
            pai[i]=x;
            sub[x]+=sub[i];
        }
    }

    void hld(int x, int atual){
        chain[x]=atual;
        pos[x]=++cont;

        seg.upd(pos[x], v[x]);

        if(heavy[x]) hld(heavy[x], atual);
        for(int i:vec[x]){
            if(i==heavy[x] || i==pai[x]) continue;
            hld(i, i);
        }
    }

    void build(){
        dfs(1, 0);
        hld(1, 1);
    }
    
    int query_path(int a, int b){
        int ans=0;

        while(chain[a]!=chain[b]){
            if(pos[chain[a]]<pos[chain[b]]) swap(a, b);

            ans=seg.join(ans, seg.query(pos[chain[a]], pos[a]));
            a=pai[chain[a]];
        }
        if(pos[a]>pos[b]) swap(a, b);

        //if the values are on the edges pos[a]+1
        ans=seg.join(ans, seg.query(pos[a], pos[b]));
        return ans;
    }

    void upd_path(int a, int b, int x){
        while(chain[a]!=chain[b]){
            if(pos[chain[a]]<pos[chain[b]]) swap(a, b);

            seg.upd(pos[chain[a]], pos[a], x);

            a=pai[chain[a]];
        }
        if(pos[a]>pos[b]) swap(a, b);

        //if the values are on the edges pos[a]+1
        seg.upd(pos[a], pos[b], x);
    }

    int query_sub(int a){
        return seg.query(pos[a], pos[a]+sub[a]-1);
    }

    void upd_sub(int a, int x){
        seg.upd(pos[a], pos[a]+sub[a]-1, x);
    }

    int query_node(int a){
        return seg.query(pos[a], pos[a]);
    }

    void upd_node(int a, int x){
        seg.upd(pos[a], x);
    }
};
