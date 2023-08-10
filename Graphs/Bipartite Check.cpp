int check(int x){
    int ans=1;
    for(int i:vec[x]){
        if(!cor[i]){
            if(cor[x]==1) cor[i]=2;
            else cor[i]=1;
            ans = min(ans, check(i));
        }else{
            if(cor[x]==cor[i]) return 0;
        }
    }
    return ans;
}
