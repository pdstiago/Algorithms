template<class T> struct SegP{
    int n, cont=0, t=0;
    vector<T> tree, lazy;
    vector<int> esq, dir, ver;

    SegP(int n, int q) : n(n), tree(3*(n+1)+18*(q+1)), esq(3*(n+1)+18*(q+1)), dir(3*(n+1)+18*(q+1)), 
    lazy(3*(n+1)+18*(q+1)), ver(q+1) {}

    T join(T a, T b){
        return a+b;
    }

    void build(int node, int l, int r, vector<int> &v){
        if(l==r){
            tree[node]=v[l];
            return;
        }
        int mid = (l+r)>>1;
        esq[node]=++cont, dir[node]=++cont;
        build(esq[node], l, mid, v);
        build(dir[node], mid+1, r, v);
        tree[node]=join(tree[esq[node]], tree[dir[node]]);
    }

    void build(vector<int> &v){
        build(ver[++t]=++cont, 1, n, v);
    }

    T query(int node, int l, int r, int a, int b){
        if(a>r || b<l) return 0; //remember to change
        if(a<=l && b>=r) return tree[node]+lazy[node];
        int mid=(l+r)>>1;
        return lazy[node] + join(query(esq[node], l, mid, a, b), query(dir[node], mid+1, r, a, b));
    }

    T query(int tt, int a, int b){
        return query(ver[tt], 1, n, a, b);
    }

    void upd(int lnode, int node, int l, int r, int pos, int val){
        if(l==r){
            tree[node]=val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid){
            upd(esq[lnode], esq[node]=++cont, l, mid, pos, val);
            tree[node] = join(tree[esq[node]], tree[dir[node]=dir[lnode]]);
        }else{
            upd(dir[lnode], dir[node]=++cont, mid+1, r, pos, val);
            tree[node] = join(tree[esq[node]=esq[lnode]], tree[dir[node]]);
        }
    }

    void upd(int lnode, int node, int l, int r, int a, int b, int val){
        tie(tree[node], lazy[node], esq[node], dir[node]) = {tree[lnode], lazy[lnode], esq[lnode], dir[lnode]};

        if(a>r || b<l) return;

        if(a<=l && b>=r){
            lazy[node]+=val;
            return;
        }

        int mid=(l+r)>>1;

        upd(esq[lnode], esq[node]=++cont, l, mid, a, b, val);
        upd(dir[lnode], dir[node]=++cont, mid+1, r, a, b, val);

        tree[node] = join(tree[esq[node]], tree[dir[node]]);

        lazy[node] = lazy[lnode];
    }

    void copy(int tt){
        ver[++t]=ver[tt];
    }

    void upd(int tt, int pos, int val){
        int prox=++cont;
        upd(ver[tt], prox, 1, n, pos, val);
        ver[tt]=prox;
    }

    void upd(int tt, int a, int b, int val){
        int prox=++cont;
        upd(ver[tt], prox, 1, n, a, b, val);
        ver[tt]=prox;
    }

    void upd_copy(int tt, int pos, int val){
        upd(ver[++t]=++cont, ver[tt], 1, n, pos, val);
    }

    void upd_copy(int tt, int a, int b, int val){
        upd(ver[++t]=++cont, ver[tt], 1, n, a, b, val);
    }
};
