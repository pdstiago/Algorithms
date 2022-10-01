void unlazy(int node, int l, int r){
    if(tree[node][1]){
        tree[node][0]=tree[node][1];
        if(l!=r){
            tree[2*node][1]=tree[node][1];
            tree[2*node+1][1]=tree[node][1];
        }
        tree[node][1]=0;
    }
}

void build(int node, int l, int r){
    if(l==r){
        tree[node][0]=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
}

void update(int node, int l, int r, int a, int b, int val){
    unlazy(node, l, r);
    if(a>r || b<l) return;
    if(l>=a && r<=b){
        tree[node][1]=val;
        unlazy(node, l, r);
        return;
    }
    int mid=(l+r)>>1;
    update(2*node, l, mid, a, b);
    update(2*node+1, mid+1, r, a, b);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
}

int query(int node, int l, int r, int a, int b){
    unlazy(node, l, r);
    if(a>r || b<l) return 0;
    if(a<=l && b>=r){
        return tree[node][0];
    }
    int mid=(l+r)>>1;
    return query(2*node, l, mid, a, b)+query(2*node+1, mid+1, r, a, b);
}
