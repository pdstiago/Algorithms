void hashing(string s){
    int p = 31; //se tiver maiúscula, 53 pode ser uma boa opção
    ll inv_p = 838709685;
    const int m = 1e9+9;
    //99999996961, 99999999119, 9999997409, 9999997561, 999996307, 
    //999998501, 99999089, 99997769, 9999907, 9993769
    p_pow[0]=1;
    inv_pow[0]=1;
    for(int i=1; i<n; i++){
        p_pow[i]=(p_pow[i-1]*p)%m;
        inv_pow[i]=(inv_pow[i-1]*inv_p)%m;
    }
    for(int i=1; i<=n; i++{
        h[i]=(h[i-1]+(s[i-1]-'a'+1)*p_pow[i-1])%m;
    }
}

ll hash_range(int l, int r){
    return ((h[r]-h[l]+m)%m*inv_pow[l])%m;
}
