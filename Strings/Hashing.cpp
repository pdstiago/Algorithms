static int C;

template<int M, class B> struct A{
    int x; 
    B b; 
    A(int x=0) : x(x), b(x) {}
    A(int x, B b) : x(x), b(b) {}
    A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
    A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
    A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
    explicit operator ull() { return x ^ (ull) b << 21; }
    bool operator==(A o) const { return (ull)*this == (ull)o; }
    bool operator<(A o) const { return (ull)*this < (ull)o; }
};

typedef A<1000000007, A<1000000009, unsigned> > H;
//remember to convert H to ull to get hash humber
//just put (ull) before the variable with type H
//ull atual = (ull) txt.range(i, i+meio);

struct Hashing{
    int n;
    vector<H> ha, pw;
    Hashing(string& str) : n((int)str.size()), ha(n+1), pw(n+1){
        pw[0]=1;
        for(int i=0; i<n; i++){
            ha[i+1] = ha[i] * C + str[i],
            pw[i+1] = pw[i] * C;
        }
    }
    H range(int a, int b){ // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

vector<H> getHashes(string& str, int tam){
    int n = (int)str.size();
    if(n<tam) return {};
    H h = 0, pw = 1;
    for(int i=0; i<tam; i++){
        h = h * C + str[i], pw = pw * C;
    }
    vector<H> ret = {h};
    for(int i=tam; i<n; i++){
        ret.push_back(h = h * C + str[i] - pw * str[i-tam]);
    }
    return ret;
}

H hashString(string& str) {H h{}; for(char c:str) h=h*C+c; return h;}

#include <sys/time.h>
int main(){
    timeval tp;
    gettimeofday(&tp, 0);
    C = (int)tp.tv_usec;
    assert((ull)(H(1)*2+1-3) == 0);
    // ...
}
