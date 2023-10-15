mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{ //0-indexed, remember to merge after spliting
    int v, p, tam;
    bool rev;
    ll sum;
    node *l, *r;
    node(int x) : v(x), p(rng()), tam(0), rev(0), sum(x), l(nullptr), r(nullptr) {}
};

int tam(node *t){
    return (t==nullptr?0:t->tam);
}

ll sum(node *t){
    return (t==nullptr?0:t->sum);
}

void upd(node *t){
    if(t==nullptr) return;
    t->tam = tam(t->l) + tam(t->r) + 1;
    t->sum = sum(t->l) + sum(t->r) + t->v;
}

void push(node *t){
    if(t==nullptr || !t->rev) return;
    swap(t->l, t->r);
    if(t->l!=nullptr) t->l->rev ^= 1;
    if(t->r!=nullptr) t->r->rev ^= 1;
    t->rev=0;
}

void merge(node *&t, node *l, node *r){
    push(l); push(r);
    if(l==nullptr) t=r;
    else if(r==nullptr) t=l;
    else if(l->p>r->p){
        merge(l->r, l->r, r);
        t=l;
    }else{
        merge(r->l, l, r->l);
        t=r;
    }
    upd(t);
}

void split(node *t, node *&l, node *&r, int k){ //k values on left
    push(t);
    if(t==nullptr) l=r=nullptr;
    else if(k<=tam(t->l)){
        split(t->l, l, t->l, k);
        r=t;
    }else{
        split(t->r, t->r, r, k-1-tam(t->l));
        l=t;
    }
    upd(t);
}

void add(node *&t, node*c, int k){
    push(t);
    if(t==nullptr) t=c;
    else if(c->p>=t->p){
        split(t, c->l, c->r, k);
        t=c;
    }
    else if(tam(t->l)>=k) add(t->l, c, k);
    else add(t->r, c, k-1-tam(t->l));
    upd(t);
}

void del(node *&t, int k){
    push(t);
    if(t==nullptr) return;
    if(tam(t->l)==k) merge(t, t->l, t->r);
    else if(tam(t->l)>k) del(t->l, k);
    else del(t->r, k);
    upd(t);
}

void insere(node *&t, int x, int pos){
    node *a = new node(x);
    add(t, a, pos);
}

void reverse(node *&t, int l, int r){
    node *t1, *t2, *t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    t2->rev ^= 1;
    merge(t, t1, t2);
    merge(t, t, t3);
}

ll query(node *&t, int l, int r){
    node *t1, *t2, *t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);
    ll ans = t2->sum;
    merge(t, t1, t2);
    merge(t, t, t3);
    return ans;
}

void print(node *t){
    if(t==nullptr) return;
    push(t);
    print(t->l);
    cout << t->v << " ";
    print(t->r);
}
node *root = nullptr;
