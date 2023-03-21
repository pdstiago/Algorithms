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
int query(int l, int r){ //index em 0, logo query(b-1, c-1)
    int ans=0;
    int cl=l/len, cr=r/len;
    if(cl==cr){
        for(int i=l; i<=r; i++) ans+=v[i];
    }else{
        for(int i=l; i<=(cl+1)*len-1; i++) ans+=v[i];
        
        for(int i=cl+1; i<=cr-1; i++) ans+=block[i];
        
        for(int i=cr*len; i<=r; i++) ans+=v[i];
    }
    return ans;
}
