//z é um vector de int que relaciona cada posição da string com um número 
//que indica o tamanho da subsequência que começa nessa posição e coincide 
//com o prefixo da string
void z_algo(string s) {
    for(int i=1, l=0, r=0; i<n; i++) {
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
}
