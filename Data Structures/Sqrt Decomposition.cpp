void build(){
    for(int i=0; i<n; i++){
        block[i/len]+=v[i];
    }
}
void upd(int id, int x){ //index em 0, logo upd(b-1, c)
    block[id/len]-=v[id];
    v[id]=x;
    block[id/len]+=v[id];
}
int query(int r){
    int ans=0;
    for(int i=0; i<r/len; i++){
        ans+=block[i];
    }
    for(int i=r/len*len; i<r; i++){
        ans+=v[i];
    }
    return ans;
}
int query(int l, int r){ //mesmo pelo index em 0, query(b, c), sem diminuir
    return query(r)-query(l-1);
}
