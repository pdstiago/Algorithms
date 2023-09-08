truct Seg{
    int n;
    vector<int> tree, lazy;

    Seg(int n){
        tree.resize(4*(n+1));
        lazy.resize(4*(n+1));
    }
    
    int join(int a, int b){
        return a+b;
    }

    void unlazy(int node, int l, int r){
        if(lazy[node]){
            tree[node]+=(r-l+1)*lazy[node]; //remember to change
            if(l!=r){
                lazy[2*node]+=lazy[node];
                lazy[2*node+1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }

    void upd(int node, int l, int r, int pos, int val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            upd(2*node, l, mid, pos, val);
        }else{
            upd(2*node+1, mid+1, r, pos, val);
        }
        tree[node]=join(tree[2*node], tree[2*node+1]);
    }

    void upd(int node, int l, int r, int a, int b, int val){
        unlazy(node, l, r);
        if(a>r || b<l) return;
        if(l>=a && r<=b){
            lazy[node]=val;
            unlazy(node, l, r);
            return;
        }
        int mid=(l+r)>>1;
        upd(2*node, l, mid, a, b, val);
        upd(2*node+1, mid+1, r, a, b, val);
        tree[node]=join(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return 0; //remember to change
        if(a<=l && b>=r) return tree[node];
        int mid=(l+r)>>1;
        return join(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
    }
};
