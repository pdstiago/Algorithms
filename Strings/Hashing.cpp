struct Hashing{
    int n;
    int m=1004669333;
    int p=33; //se tiver maiúscula, 53 pode ser uma boa opção
    int inv_p=121778101;
    vector<ll> p_pow, inv_pow, h, inv_h;
    string s;

    Hashing(string s) : s(s){
        n=s.size();
        p_pow.resize(n+1);
        inv_pow.resize(n+1);
        h.resize(n+1);
        inv_h.resize(n+1);
    }

    void build(){
        p_pow[0]=1;
        inv_pow[0]=1;
        for(int i=1; i<n; i++){
            p_pow[i]=(p_pow[i-1]*p)%m;
            inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
        }
        for(int i=1; i<=n; i++){
            h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
            inv_h[i]=(inv_h[i-1]+(s[i-1]-'a'+1)*inv_pow[i-1])%m;
        }
    }

    int range(int l, int r){ //index em 0
        return ((h[r+1]-h[l]+m)*inv_pow[l])%m;
    }

    int inv_range(int l, int r){ //index em 0
        return ((inv_h[r+1]-inv_h[l]+m)*p_pow[l])%m;
    }
};
