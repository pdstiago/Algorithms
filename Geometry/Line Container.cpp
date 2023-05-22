//acha o maior valor de y para um determinado x, para retas da forma ax + b que estão na estrutura
struct Line{
    mutable ll k, m, p;
    bool operator<(const Line& o) const {return k<o.k;}
    bool operator<(ll x) const {return p<x;}
};

struct LineContainer : multiset<Line, less<>>{
    ll div(ll a, ll b){
        return a/b-((a^b)<0 && a%b);
    }

    int issect(iterator x, iterator y){
        if(y==end()) {x->p=INFL; return 0;}
        if(x->k==y->k) x->p=x->m > y->m?INFL:-INFL;
        else x->p=div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    
    //para achar o mínimo, é preciso fazer insert({-k, -m, 0}), além disso multiplicar por -1 o resultado da query
    void add(ll k, ll m){
        auto z=insert({k, m, 0}), y=z++, x=y;
        while(issect(y, z)) z=erase(z);
        if(x!=begin() && issect(--x, y)) issect(x, y=erase(y));
        while((y=x) != begin() && (--x)->p >= y->p) issect(x, erase(y));
    }
    
    ll query(ll x){
        assert(!empty());
        auto l=*lower_bound(x);
        return l.k*x+l.m;
    }
};
