vector<int> fact(int x){ // O(sqrt(N))
    vector<int> factors;

    if(x%2==0) factors.pb(2);
    while(x%2==0) x>>=1;

    for(int i=3; i*i<=x; i+=2){
        if(x%i==0) factors.pb(i);
        while(x%i==0) x/=i;
    }

    if(x>2) factors.pb(x);

    return factors;
}
