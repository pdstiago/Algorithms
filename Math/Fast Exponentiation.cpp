int mod(ll a){
    return (a%MOD + MOD)%MOD;
}
ll exp(ll b, ll e){
    ll res=1;
    while(e){
        if(e&1){
            res=mod(res*b);
        }
        b=mod(b*b);
        e>>=1;
    }
    return res;
}
