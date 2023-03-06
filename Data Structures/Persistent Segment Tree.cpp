struct no{
    int val;
    no *l, *r;
    no(int v){
        l=nullptr, r=nullptr, val=v;
    }
    no(no *left, no *right){
        l=left, r=right, val=0;
        if(l) val+=l->val;
        if(r) val+=r->val;
    }
};

no* build(int l=1, int r=n){
    if(l==r){
        return new no(v[l]);
    }
    int mid=(l+r)>>1;
    return new no(build(l, mid), build(mid+1, r));
}

no* upd(no *node, int l=1, int r=n, int id, int val){
    if(l==r){
        return new no(val);
    }
    int mid=(l+r)>>1;
    if(l<=id && id<=mid){
        return new no(upd(node->l, l, mid, id, val), node->r);
    }
    return new no(node->l, upd(node->r, mid+1, r, id, val));
}

int query(no *node, int l=1, int r=n, int a, int b){
    if(b<l || a>r) return 0;
    if(l>=a && r<=b){
        return node->val;
    }
    int mid=(l+r)>>1;
    return query(node->l, l, mid, a, b)+query(node->r, mid+1, r, a, b);
}

//no *version[mxn];
//version[1]=build();
//version[++cont]=upd(version[cont-1], c, d);
//query(version[k], c, d)
