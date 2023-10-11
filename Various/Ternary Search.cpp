//< for maximum and > for minimum value
int ternary(int l, int r){
    while(r-l>=5){    
        int mid=(l+r)>>1;
        if(f(mid)<f(mid+1)){
            l=mid;
        }else{
            r=mid+1;
        }
    }
    for(int i=l+1; i<=r; i++){
        if(f(l)<f(i)) l=i;
    }
    return l;
}

double ternary(double l, double r){
    int cont=200;
    while(cont--){
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        double f1=f(m1);
        double f2=f(m2);
        if(f1<f2){
            l=m1;
        }else{
            r=m2;
        }
    }
    return l;
}
