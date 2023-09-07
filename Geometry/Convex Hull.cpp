vector<P> ch(){
    sort(v.begin(), v.end());

    vector<P> upper, lower, convex;
    
    // a condição do cross será < quando incluir colinear, senão <=
    // #define sz(x) (int)x.size()
    
    for(int i=0; i<n; i++){
        while(sz(upper)>1 && v[i].cross(upper[sz(upper)-2], upper[sz(upper)-1])<0){
            upper.pop_back();
        }
        upper.push_back(v[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(sz(lower)>1 && v[i].cross(lower[sz(lower)-2], lower[sz(lower)-1])<0){
            lower.pop_back();
        }
        lower.push_back(v[i]);
    }
    for(int i=0; i<sz(upper)-1; i++){
        convex.push_back(upper[i]);
    }
    for(int i=0; i<sz(lower)-1; i++){
        convex.push_back(lower[i]);
    }
    return convex;
}
