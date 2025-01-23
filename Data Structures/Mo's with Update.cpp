const int B = 2500; // N = 2e5
struct query {
    int l, r, t, id;
    bool operator < (const query &x) const {
        if(l / B == x.l / B) {
            if(r / B == x.r / B) return t < x.t;
            return r / B < x.r / B;
        }
        return l / B < x.l / B;
    }
} Q[mxn];

struct upd {
    int pos, old, cur;
} U[mxn];

int l, r, t;

void update(int pos, int x){
    if(l<=pos && pos<=r){
        add(x);
        del(v[pos]);
    }
    v[pos] = x;
}

void mos(){
    int nq = 0, nu = 0;
    for(int i=0; i<q; i++){
        int tt, l, r;
        cin >> tt >> l >> r;
        if(tt == 1){
            nq++;
            Q[nq] = {l, r, nu, nq};
        }else{
            nu++;
            U[nu].pos = l, U[nu].old = v[l], v[l] = r, U[nu].cur = r;
        }
    }
    sort(Q+1, Q+1+nq);
    t = nu, l = 1, r = 0;
    for(int i=1; i<=nq; i++){
        int L = Q[i].l, R = Q[i].r, T = Q[i].t;
        while(t < T) t++, update(U[t].pos, U[t].cur);
        while(t > T) update(U[t].pos, U[t].old), t--;
        if(R < l){
            while(l > L) add(v[--l]);
            while(l < L) del(v[l++]);
            while(r < R) add(v[++r]);
            while(r > R) del(v[r--]);
        }else{
            while(r < R) add(v[++r]);
            while(r > R) del(v[r--]);
            while(l > L) add(v[--l]);
            while(l < L) del(v[l++]);
        }
        ans[Q[i].id] = cont;
    }
}