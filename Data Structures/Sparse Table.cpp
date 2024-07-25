template <class T> struct RMQ{ // 0-indexed
    int lg;
    vector<vector<T> > tab;

    T join(T a, T b){
        return min(a, b);
    }

    RMQ() {}

    RMQ(vector<T> &v){
        int n = (int)v.size();
        lg = __lg(n)+1;
        tab.resize(lg);
        tab[0]=v;
        for(int j=1; j<lg; j++){
            tab[j].resize(n-(1<<j)+1);
            for(int i=0; i+(1<<j)<=n; i++){
                tab[j][i]=join(tab[j-1][i], tab[j-1][i+(1<<(j-1))]);
            }
        }
    }

    T query_min(int l, int r){ //[l, r)
        int k = __lg(r-l);
        return min(tab[k][l], tab[k][r-(1<<k)]);
    }

    T query_sum(int l, int r){ //[l, r)
        T ans=0;
        for(int i=lg-1; i>=0; i--){
            if(l+(1<<i)<=r){
                ans+=tab[i][l];
                l+=(1<<i);
            }
        }
        return ans;
    }
};