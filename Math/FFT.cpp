template<typename dbl> struct cplx{
    dbl x, y; using P = cplx;
    cplx(dbl x_=0, dbl y_=0) : x(x_), y(y_) {}
    friend P operator+(P a, P b) { return P(a.x+b.x, a.y+b.y); }
    friend P operator-(P a, P b) { return P(a.x-b.x, a.y-b.y); }
    friend P operator*(P a, P b) { return P(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x); }
    friend P conj(P a) { return P(a.x, -a.y); }
    friend P inv(P a) { dbl n = (a.x*a.x+a.y*a.y); return P(a.x/n,-a.y/n); }
};
template<typename T> struct root_of_unity {};
template<typename dbl> struct root_of_unity<cplx<dbl>>{
    static cplx<dbl> f(int k){
        static const dbl PI = acos(-1); dbl a = 2*PI/k;
        return cplx<dbl>(cos(a), sin(a));
    }
};
typedef cplx<double> cd;
inline int nxt_pow2(int s) { return 1 << (s>1 ? 32-__builtin_clz(s-1) : 0); }
template<typename T> struct FFT{
    vector<T> rt; vector<int> rev;
    FFT() : rt(2, T(1)) {}
    void init(int N){
        N = nxt_pow2(N);
        if(N>int(rt.size())){
            rev.resize(N); rt.reserve(N);
            for(int a=0; a<N; a++) rev[a] = (rev[a/2] | ((a&1)*N)) >> 1;
            for(int k=int(rt.size()); k<N; k*=2){
                rt.resize(2*k);
                T z = root_of_unity<T>::f(2*k);
                for(int a=k/2; a<k; a++) rt[2*a] = rt[a], rt[2*a+1] = rt[a]*z;
            }
        }
    }
    void fft(vector<T>& xs, bool inverse) const{
        int N = int(xs.size());
        int s = __builtin_ctz(int(rev.size())/N);
        if(inverse) reverse(xs.begin()+1, xs.end());
        for(int a=0; a<N; a++){
            if(a<(rev[a] >> s)) swap(xs[a], xs[rev[a] >> s]);
        }
        for(int k=1; k<N; k*=2){
            for(int a=0; a<N; a+=2*k){
                int u = a, v = u+k;
                for(int b=0; b<k; b++, u++, v++){
                    T z = rt[b+k]*xs[v];
                    xs[v] = xs[u]-z, xs[u] = xs[u]+z;
                }
            }
        }
        if(inverse) for(int a=0; a<N; a++) xs[a] = xs[a]*inv(T(N));
    }
    vector<T> convolve(vector<T> as, vector<T> bs){
        int N = int(as.size()), M = int(bs.size());
        int K = N+M-1, S = nxt_pow2(K); init(S);
        if(min(N, M)<=64){
            vector<T> res(K);
            for(int u=0; u<N; u++){
                for(int v=0; v<M; v++){
                    res[u+v] = res[u+v]+as[u]*bs[v];
                }
            }
            return res;
        }else{
            as.resize(S), bs.resize(S);
            fft(as, false); fft(bs, false);
            for(int i=0; i<S; i++) as[i] = as[i]*bs[i];
            fft(as, true); as.resize(K); return as;
        }
    }
};
/*
vector<cd> a(n), b(m);
FFT<cd> fft;
vector<cd> mult = fft.convolve(a, b);
(mult[i].x + 0.5) or -0.5
(roundll(mult[i].x))
*/