struct node{
    ll sum, pref, suf, ans;
}tree[4*mxn];

node make_node(int val){
    node res;
    res.sum=val;
    res.pref=res.suf=res.ans=max(0, val);
    return res;
}

node combine(node l, node r){
    node res;
    res.sum=l.sum+r.sum;
    res.pref=max(l.pref, l.sum+r.pref);
    res.suf=max(r.suf, r.sum+l.suf);
    res.ans=max({l.ans, r.ans, l.suf+r.pref});
    return res;
}

void build(int node=1, int l=1, int r=n){
    if(l==r){
        tree[node]=make_node(v[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node]=combine(tree[2*node], tree[2*node+1]);
}

void upd(int node=1, int l=1, int r=n, int id, int val){
    if(l==r){
        tree[node]=make_node(val);
        return;
    }
    int mid=(l+r)>>1;
    if(l<=id && id<=mid){
        upd(2*node, l, mid, id, val);
    }else{
        upd(2*node+1, mid+1, r, id, val);
    }
    tree[node]=combine(tree[2*node], tree[2*node+1]);
}

node query(int node=1, int l=1, int r=n, int a, int b){
    if(b<l || a>r) return make_node(0);
    if(l>=a && r<=b) return tree[node];
    int mid=(l+r)>>1;
    return combine(query(2*node, l, mid, a, b), query(2*node+1, mid+1, r, a, b));
}
