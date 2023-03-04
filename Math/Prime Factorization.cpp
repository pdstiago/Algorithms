vector<int> fatoracao(int n){
    vector<int> fatores;
    while(!(n&1)){
        fatores.push_back(2);
        n>>=1;
    }
    for(int i=3; i*i<=n; i+=2){
        while(n%i==0){
            fatores.push_back(i);
            n/=i;
        }
    }
    if(n!=1) fatores.push_back(n);
    return fatores;
}
