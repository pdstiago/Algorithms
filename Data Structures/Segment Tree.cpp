struct SEG{
    int n;
    vector<int> tree, lazy;

    void build(int n_){
        n = n_;
        tree.resize(4*(n+1));
        lazy.resize(4*(n+1));
    }

    void unlazy(int node, int l, int r){
        if(lazy[node]){
            tree[node]+=(r-l+1)*lazy[node];
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }

    void upd_solo(int node, int l, int r, int id, int val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(l<=id && id<=mid) upd_solo(2*node, l, mid, id, val);
        else upd_solo(2*node+1, mid+1, r, id, val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }

    void upd_range(int node, int l, int r, int a, int b, int val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node]=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd_range(2*node, l, mid, a, b, val);
        upd_range(2*node+1, mid+1, r, a, b, val);
        tree[node]=tree[2*node]+tree[2*node+1];
    }

    int query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return 0;
        if(a<=l && b>=r){
            return tree[node];
        }
        int mid=(l+r)>>1;
        return query(2*node, l, mid, a, b)+query(2*node+1, mid+1, r, a, b);
    }
};
