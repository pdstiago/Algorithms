//Z relaciona cada posição i da string com um número que indica o tamanho da subsequência que começa nessa posição i e 
//coincide com o prefixo da string.
//Em outras palavras, Z[i] é o tamanho da maior string, que é prefixo de S e um prefixo do sufixo de S que começa na posição i.
vector<int> build(string &s){ // O(N)
    int n = (int)s.size();
    vector<int> z(n);
    for(int i=1, l=0, r=0; i<n; i++){
        if(i<=r){
            z[i]=min(r-i+1, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l=i, r=i+z[i]-1;
        }
    }
    return z;
}
