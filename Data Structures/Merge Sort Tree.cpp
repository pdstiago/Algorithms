vector<int> tree[4*mxn];

void build(int node=1, int l=1, int r=n){
    if(l==r){
        tree[node].pb(v[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), back_inserter(tree[node]));
}

int query(int a, int b, int x, int node=1, int l=1, int r=n){
    if (b<l || a>r) return 0;
    if(l>=a && r<=b){
        //qnt de números iguais a x
        auto it = upper_bound(tree[node].begin(), tree[node].end(), x);
        auto it2 = lower_bound(tree[node].begin(), tree[node].end(), x);
        if(*it2==x){
            int pos1=it-tree[node].begin();
            int pos2=it2-tree[node].begin();
            return pos1-pos2;
        }
        return 0;
    }
    int mid=(l+r)>>1;
    return query(a, b, x, 2*node, l, mid)+query(a, b, x, 2*node+1, mid+1, r);
}
