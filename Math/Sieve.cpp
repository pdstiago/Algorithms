void crivo(){
    n_primo[1]=1;
    for(int i=2; i<=n; i++){
        if(n_primo[i]) continue;
        for(int j=2; i*j<=n; j++){
            n_primo[i*j]=1;
        }
    }
}
