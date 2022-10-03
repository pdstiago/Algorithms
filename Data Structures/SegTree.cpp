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

void upd(int node, int l, int r, int id, int val){
    if(l==r){
        tree[node]=val;
        v[l]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(l<=id && id<=mid){
        upd(2*node, l, mid, id, val);
    }else{
        upd(2*node+1, mid+1, r, id, val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node, int l, int r, int a, int b){
    if(b<l || a>r) return 0;
    if(l>=a && r<=b) return tree[node];
    int mid=(l+r)>>1;
    return query(2*node, l, mid, a, b)+query(2*node+1, mid+1, r, a, b);
}
