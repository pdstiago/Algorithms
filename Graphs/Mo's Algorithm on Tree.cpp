struct query{
    int l, r, id, lca;
}q[mxm];
//same ord of regular mo's
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
            //se o valor tiver na aresta, então não precisa do q[i].lca e
            //q[i].l=tout[b], q[i].r=tout[a]-1;
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
    //se o valor tiver na aresta curl=1, curr=0;
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
            add(q[i].lca);
        }
        resp[q[i].id]=ans;
        if(q[i].lca!=-1){
            remove(q[i].lca);
        }
    }
}
