int lp[mxn]; //lp[i] is the lowest prime factor of i

vector<int> crivo(int N){ // O(N)
    vector<int> primes;
    for(int i=2; i<=N; i++){
        if(!lp[i]){
            lp[i]=i;
            primes.push_back(i);
        }
        for(int p:primes){
            if(i>N/p) break;
            lp[i*p]=p;
            if(i%p==0) break;
        }
    }
    return primes;
}
