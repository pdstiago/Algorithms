void dfs(int x){
    for(int i:vec[x]){
        if(!cor[i]){
            if(cor[x]==1){
                cor[i]=2;
            }else{
                cor[i]=1;
            }
            dfs(i);
        }else{
            if(cor[x]==cor[i]){
                check=1;
            }
        }
    }
}
