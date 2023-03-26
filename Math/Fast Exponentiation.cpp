ll exp(ll b, ll e){
	ll res=1;
	while(e){
	if(e&1){
	    res=mod(res*b, MOD);
	    res=mod(res, MOD);
	}
	b=mod(b*b, MOD);
	b=mod(b, MOD);
	    e>>=1;
	}
	return res;
}
