vector<P> ch(vector<P> &v){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    if(v.size()<=1) return v;

    vector<P> up, lw, cv;
    
    // a condição do cross será < quando incluir colinear, senão <=
    
    int n = (int)v.size();
    for(int i=0; i<n; i++){
        while(lw.size()>1 && v[i].cross(lw[lw.size()-2], lw[lw.size()-1])>=0) lw.pop_back();
        lw.push_back(v[i]);
    }
    for(int i=n-1; i>=0; i--){
        while(up.size()>1 && v[i].cross(up[up.size()-2], up[up.size()-1])>=0) up.pop_back();
        up.push_back(v[i]);
    }
    lw.pop_back();
    up.pop_back();
    cv = up;
    for(P i:lw) cv.push_back(i);
    return cv;
}
