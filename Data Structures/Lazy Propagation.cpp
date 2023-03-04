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

void build(int node, int l, int r){
    if(l==r){
        tree[node]=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node]=tree[2*node]+tree[2*node+1];
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
