int exp(int b, int e, int m=MOD){ // O(logE)
    int res=1;
    while(e){
        if(e&1) res=(res*b)%m;
        b=(b*b)%m;
        e>>=1;
    }
    return res;
}
