ll cross(pii a, pii b, pii c){
    pii v1={c.f-a.f, c.s-a.s};
    pii v2={b.f-a.f, b.s-a.s};
    return v1.f*v2.s-v1.s*v2.f;
}

void ch(){
    sort(v, v+n);
    vector<pii> upper, lower, convex;
    for(int i=0; i<n; i++){
        while(sz(upper)>1 && cross(upper[sz(upper)-2], upper[sz(upper)-1], v[i])<=0){
            upper.pop_back();
        }
        upper.pb(v[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(sz(lower)>1 && cross(lower[sz(lower)-2], lower[sz(lower)-1], v[i])<=0){
            lower.pop_back();
        }
        lower.pb(v[i]);
    }
    for(int i=0; i<sz(upper)-1; i++){
        convex.pb(upper[i]);
    }
    for(int i=0; i<sz(lower)-1; i++){
        convex.pb(lower[i]);
    }
    cout << sz(convex) << endl;
    for(pii i:convex){
        cout << i.f << es << i.s << endl;
    }
}
