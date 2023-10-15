template <class T> struct Seg{
    int n, neutral=0;
    vector<T> tree, lazy;

    Seg(int n) : n(n), tree(4*(n+1)), lazy(4*(n+1)) {}
    
    T join(T a, T b){
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

    T query(int node, int l, int r, int a, int b){
        unlazy(node, l, r);
        if(a>r || b<l) return neutral; //remember to change
        if(a<=l && b>=r) return tree[node];
        int mid=(l+r)>>1;
        return join(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
    }

    int busca(int node, int l, int r, int a, int b, int val){ //primeira posição com valor > que val
        if(a>r || b<l) return -1;
        if(l>=a && r<=b){
            if(tree[node]<=val) return -1;
            while(l!=r){
                int mid = (l+r)>>1;
                if(tree[2*node]>val){
                    node=2*node;
                    r=mid;
                }else{
                    node=2*node+1;
                    l=mid+1;
                }
            }
            return l;
        }
        int mid=(l+r)>>1;
        int ans = busca(2*node, l, mid, a, b, val);
        if(ans!=-1) return ans;
        return busca(2*node+1, mid+1, r, a, b, val);
    }

    void upd(int pos, int val){
        upd(1, 1, n, pos, val);
    }

    void upd(int l, int r, int val){
        upd(1, 1, n, l, r, val);
    }

    T query(int l, int r){
        return query(1, 1, n, l, r);
    }

    int upper(int l, int r, int val){
        return busca(1, 1, n, l, r, val);
    }
};
