struct HLD{
    int n, cont=0;
    vector<int> sub, pai, heavy, head, pos, v, tree;
    vector<vector<int> > vec;

    HLD(int n) : n(n){
        sub.resize(n+1);
        pai.resize(n+1);
        heavy.resize(n+1);
        head.resize(n+1);
        pos.resize(n+1);
        v.resize(n+1);
        tree.resize(4*n+1);
        vec.resize(n+1);
    }

    void upd(int node, int l, int r, int id, int val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(l<=id && id<=mid) upd(2*node, l, mid, id, val);
        else upd(2*node+1, mid+1, r, id, val);
        tree[node]=min(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int a, int b){
        if(b<l || a>r) return INF;
        if(l>=a && r<=b) return tree[node];
        int mid=(l+r)>>1;
        return min(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
    }

    void add_edge(int a, int b){
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    void dfs(int x=1, int p=0){
        sub[x]=1;
        int maior=0;
        for(int i:vec[x]){
            if(i==p) continue;
            dfs(i, x);
            pai[i]=x;
            if(sub[i]>maior) maior=sub[i], heavy[x]=i;
            sub[x]+=sub[i];
        }
    }

    void hld(int x=1, int atual=1){
        head[x]=atual;
        pos[x]=++cont;
        upd(1, 1, n, cont, v[x]);
        if(heavy[x]){
            hld(heavy[x], atual);
        }
        for(int i:vec[x]){
            if(i==heavy[x] || i==pai[x]) continue;
            hld(i, i);
        }
    }

    void build(){
        dfs();
        hld();
    }
    
    int query_hld(int a, int b){
        int ans=INF;
        while(head[a]!=head[b]){
            if(pos[head[a]]<pos[head[b]]) swap(a, b);
            ans=min(ans, query(1, 1, n, pos[head[a]], pos[a]));
            a=pai[head[a]];
        }
        if(pos[a]>pos[b]) swap(a, b);
        //if the values are on the edges pos[a]+1
        ans=min(ans, query(1, 1, n, pos[a], pos[b]));
        return ans;
    }
};
