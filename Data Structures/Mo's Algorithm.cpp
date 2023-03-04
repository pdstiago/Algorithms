struct query{
    int l, r, id;
}q[mxm];
bool ord(query a, query b){
    if(a.l/len!=b.l/len){
        return make_pair(a.l, a.r)<
        make_pair(b.l, b.r);
    }
    if(a.l/len & 1){
        return a.r<b.r;
    }
    return a.r>b.r;
}
void mos(){ //index em 0 - O((N+M)*sqrt(N))
    sort(q, q+m, ord);
    int curl=0, curr=-1;
    for(int i=0; i<m; i++){
        while(curl>q[i].l){
            add(--curl);
        }
        while(curr<q[i].r){
            add(++curr);
        }
        while(curl<q[i].l){
            remove(curl++);
        }
        while(curr>q[i].r){
            remove(curr--);
        }
        resp[q[i].id]=ans;
    }
}
