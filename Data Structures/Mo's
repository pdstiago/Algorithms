struct query{
    int l, r, id;
};

len=(int)sqrt(n);

bool ord(query a, query b){
    if(a.l/len!=b.l/len){
        return make_pair(a.l, a.r)<make_pair(b.l, b.r);
    }
    if(a.l/len & 1){
        return a.r<b.r;
    }else{
        return a.r>b.r;
    }
}

for(int i=0; i<m; i++){
    cin >> q[i].l >> q[i].r;
    q[i].l--, q[i].r--;
    q[i].id=i;
}
int curl=0, curr=-1;
sort(q, q+m, ord);
for(int i=0; i<m; i++){
    while(curl>q[i].l){
        curl--;
        if(!sla[v[curl]]){
            cont++;
        }
        sla[v[curl]]++;
    }
    while(curr<q[i].r){
        curr++;
        if(!sla[v[curr]]){
            cont++;
        }
        sla[v[curr]]++;
    }
    while(curl<q[i].l){
        sla[v[curl]]--;
        if(!sla[v[curl]]){
            cont--;
        }
        curl++;
    }
    while(curr>q[i].r){
        sla[v[curr]]--;
        if(!sla[v[curr]]){
            cont--;
        }
        curr--;
    }
    resp[q[i].id]=cont;
}
