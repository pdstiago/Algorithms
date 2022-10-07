ll cross(pii a, pii b, pii c){
    pii v1={c.f-a.f, c.s-a.s};
    pii v2={b.f-a.f, b.s-a.s};
    return v1.f*v2.s-v1.s*v2.f;
}

int cmp(int a){
    if(a>0) return 1;
    if(a<0) return -1;
    return a;
}

int inter(int a, int b, int c, int d){
    if(a>b) swap(a, b);
    if(c>d) swap(c, d);
    return max(a, c)<=min(b, d);
}

int intersect(pii a, pii b, pii c, pii d){
    // segment AB and segment CD
    int o1=cmp(cross(a, b, c));
    int o2=cmp(cross(a, b, d));
    int o3=cmp(cross(c, d, a));
    int o4=cmp(cross(c, d, b));
    if(cmp(cross(c, a, d))==0 && cmp(cross(c, b, d))==0){
        return inter(a.f, b.f, c.f, d.f) && inter(a.s, b.s, c.s, d.s);
    }
    return o1!=o2 && o3!=o4;
}
