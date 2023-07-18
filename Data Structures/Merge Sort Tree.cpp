vector<int> tree[4*mxn];

void build(int node, int l, int r){
    if(l==r){
        tree[node].pb(v[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node]));
}

int query(int node, int l, int r, int a, int b, int x){
    if (b<l || a>r) return 0;
    if(l>=a && r<=b){
        //qnt de números maiores que x
        auto it = upper_bound(tree[node].begin(), tree[node].end(), x);
        return tree[node].end()-it;
    }
    int mid=(l+r)>>1;
    return query(a, b, x, 2*node, l, mid)+query(a, b, x, 2*node+1, mid+1, r);
}
