void bfs(int x){
	memset(memo, 0, sizeof (memo)); 
	memset(dist, 0, sizeof (dist));
	queue<int> fila;
	memo[x]=1;
	fila.push(x);
	while(!fila.empty()){
		int no=fila.front();
		fila.pop();
		for(int i=0; i<tree[no].size() ; i++){
			int v=tree[no][i];
			if(memo[v]==0){
				dist[v]=dist[no]+1;
				memo[v]=1;
				pai[v]=no;
				fila.push(v);
			}
		}
	}
}
bfs(1);
int maior=-1, pos;
for(int i=1; i<=n; i++){
	if(dist[i]>maior){
	    maior=dist[i];
	    pos=i;
	}
}
bfs(pos);
int diametro=-1, raio, centro, atual;
for(int i=1; i<=n; i++){
	if(dist[i]>diametro){
		diametro=dist[i];
		atual=i;
	}
}
raio=(diametro+1)/2;
while(dist[atual]>diametro/2){
	atual=pai[atual];
}
centro=atual;
