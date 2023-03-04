struct query{
    int l, r, id, lca;
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
void dfs(int x, int p){
    tin[x]=timer++;
    st.pb(x);
    for(int i:vec[x]){
        if(i==p) continue;
        anc[i][0]=x;
        lv[i]=lv[x]+1;
        dfs(i, x);
    }
    st.pb(x);
    tout[x]=timer++;
}
void construct(){
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        int c=lca(a, b);
        if(tin[a]>tin[b]) swap(a, b);
        if(a==c){
            q[i].l=tin[a], q[i].r=tin[b];
            q[i].lca=-1;
        }else{
            q[i].l=tout[a], q[i].r=tin[b];
            q[i].lca=tin[c];
        }
        q[i].id=i;
    }
}
void add(int x){
    int node=st[x];
    freq[node]++;
    if(freq[node]==1){
        //adiciono
    }else if(freq[node]==2){
        //removo
    }
    
}
void remove(int x){
    int node=st[x];
    freq[node]--;
    if(!freq[node]){
        //removo
    }else if(freq[node]==1){
        //adiciono
    }
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
        if(q[i].lca!=-1){
            add(q[i].flag);
        }
        resp[q[i].id]=ans;
        if(q[i].lca!=-1){
            remove(q[i].flag);
        }
    }
}
