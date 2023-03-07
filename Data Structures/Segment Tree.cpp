void build(int node=1, int l=1, int r=n){
    if(l==r){
        tree[node]=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid), build(2*node+1, mid+1, r);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void upd(int id, int val, int node=1, int l=1, int r=n){
    if(l==r){
        tree[node]=val, v[l]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(l<=id && id<=mid) upd(id, val, 2*node, l, mid);
    else upd(id, val, 2*node+1, mid+1, r);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int a, int b, int node=1, int l=1, int r=n){
    if(b<l || a>r) return 0;
    if(l>=a && r<=b) return tree[node];
    int mid=(l+r)>>1;
    return query(a, b, 2*node, l, mid)+query(a, b, 2*node+1, mid+1, r);
}
