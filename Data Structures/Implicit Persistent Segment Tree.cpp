struct SegP{
    int n, cont=0, t=0;
    vector<int> tree, lazy;
    vector<int> esq, dir, ver;

    SegP(int n, int q) : n(n), tree(2*(n+1)+4*18*(q+1)), esq(5*(n+1)+4*18*(q+1)), dir(2*(n+1)+4*18*(q+1)), 
    lazy(2*(n+1)+4*18*(q+1)), ver(q+2) {}

    int join(int a, int b){
        return a+b;
    }

    int newleaf(int val){
        int node = ++cont;
        esq[node] = dir[node] = 0;
        tree[node] = val;
        return node;
    }

    int newpai(int l, int r){
        int node = ++cont;
        esq[node] = l, dir[node] = r;
        tree[node] = join(tree[l], tree[r]);
        return node;
    }

    int build(int l, int r, vector<int> &v){
        if(l==r) return newleaf(v[l]);
        int mid = (l+r)>>1;
        return newpai(build(l, mid, v), build(mid+1, r, v));
    }

    void build(vector<int> &v){
        ver[t] = build(1, n, v);
    }

    int newlazy(int node, int l, int r, int val){
        int no = ++cont;
        esq[no] = esq[node], dir[no] = dir[node];
        lazy[no] = lazy[node];
        lazy[no]+=val;
        tree[no] = tree[node]+(r-l+1)*val;
        return no;
    }

    void unlazy(int node, int l, int r){
        if(lazy[node]){
            if(l!=r){
                int mid=(l+r)>>1;
                esq[node] = newlazy(esq[node], l, mid, lazy[node]);
                dir[node] = newlazy(dir[node], mid+1, r, lazy[node]);
            }
            lazy[node]=0;
        }
    }

    int upd(int node, int l, int r, int pos, int val){
        if(l==r) return newleaf(val);
        int mid=(l+r)>>1;
        if(pos<=mid){
            return newpai(upd(esq[node], l, mid, pos, val), dir[node]);
        }
        return newpai(esq[node], upd(dir[node], mid+1, r, pos, val));
    }

    int upd(int node, int l, int r, int a, int b, int val){
        if(a>r || b<l) return node;
        if(a<=l && b>=r) return newlazy(node, l, r, val);
        unlazy(node, l, r);
        int mid=(l+r)>>1;
        return newpai(upd(esq[node], l, mid, a, b, val), upd(dir[node], mid+1, r, a, b, val));
    }

    int query(int node, int l, int r, int a, int b){
        if(a>r || b<l) return 0; //remember to change
        if(a<=l && b>=r) return tree[node];
        unlazy(node, l, r);
        int mid=(l+r)>>1;
        return join(query(esq[node], l, mid, a, b), query(dir[node], mid+1, r, a, b));
    }

    int query(int tt, int a, int b){
        return query(ver[tt], 1, n, a, b);
    }

    void copy(int tt){
        ver[++t]=ver[tt];
    }

    void upd(int tt, int pos, int val){
        ver[tt] = upd(ver[tt], 1, n, pos, val);
    }

    void upd(int tt, int a, int b, int val){
        ver[tt] = upd(ver[tt], 1, n, a, b, val);
    }

    void upd_copy(int tt, int pos, int val){
        ver[++t] = upd(ver[tt], 1, n, pos, val);
    }

    void upd_copy(int tt, int a, int b, int val){
        ver[++t] = upd(ver[tt], 1, n, a, b, val);
    }
};
