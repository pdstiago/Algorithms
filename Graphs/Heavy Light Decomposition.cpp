void dfs(int x=1, int p=0){
    sub[x]=1;
    int maior=0;
    for(int i:vec[x]){
        if(i==p) continue;
        dfs(i, x);
        pai[i]=x;
        if(sub[i]>maior) maior=sub[i], heavy[x]=i;
        sub[x]+=sub[i];
    }
}
void hld(int x=1, int atual=1){
    head[x]=atual;
	pos[x]=++cont;
    upd(cont, v[x]);
    if(heavy[x]){
        hld(heavy[x], atual);
    }
    for(int i:vec[x]){
        if(i==heavy[x] || i==pai[x]) continue;
        hld(i, i);
    }
}
int query_hld(int a, int b) {
    int ans=0;
	while(head[a]!=head[b]){
		if(pos[head[a]]<pos[head[b]]) swap(a, b);
		ans=max(ans, query_seg(pos[head[a]], pos[a]));
		a=pai[head[a]];
	}
	if(pos[a]>pos[b]) swap(a, b);
	ans=max(ans, query_seg(pos[a], pos[b]));
	return ans;
}
