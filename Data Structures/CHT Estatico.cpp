// Créditos: Blog do CF do meooow
// CHT com as slopes ordenadas e as queries ordenadas
struct line{
    ll m, c;
    ll eval(ll x) { return m*x+c; }
    long double intersectX(line l) { return (long double)(c-l.c)/(l.m-m); }
};
deque<line> dq;
dq.push_front({0, 0});
ll ans = 0;
for(int i=1; i<=n; i++){
    while(dq.size()>=2 && dq.back().eval(rects[i].q)<=dq[dq.size()-2].eval(rects[i].q)) 
        dq.pop_back();
    ll f = dq.back().eval(rects[i].q)+rects[i].p * 1LL * rects[i].q-rects[i].a;
    ans=max(ans, f);
    line cur = {-rects[i].p, f};
    while(dq.size()>=2 && cur.intersectX(dq[0])>=dq[0].intersectX(dq[1])) dq.pop_front();
    dq.push_front(cur);
}

// CHT com as slopes ordenadas e as queries em ordem arbitrária
deque<line> dq;
vector<int> ints(n);
iota(ints.begin(), ints.end(), 0);
auto cmp = [&dq](int idx, int x) { return dq[idx].intersectX(dq[idx+1])<x; };
dq.push_front({0, 0});
ll ans = 0;
for(int i=1; i<=n; i++){
    int idx = *lower_bound(ints.begin(), ints.begin()+dq.size()-1, a[i].q, cmp);
    ll f = dq[idx].eval(rects[i].q)+rects[i].p * 1LL * rects[i].q-rects[i].a;
    ans = max(ans, f);
    line cur = {-rects[i].p, f};
    while(dq.size()>=2 && cur.intersectX(dq[0])>=dq[0].intersectX(dq[1])) dq.pop_front();
    dq.push_front(cur);
}
