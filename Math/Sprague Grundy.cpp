int mex(){
    for(int i=0; ; i++){
        if(used[i]!=version){
            return i;
        }
    }
}
void grundy(){
    //casos bases
    g[0]=0;
    g[1]=1;
    g[2]=2;
    //transição
    for(int i=3; i<MXN; i++){
        version++;
        used[g[i-1]]=version;
        used[g[i-2]]=version;
        used[g[i-3]]=version;
        g[i]=mex();
    }
}

int solve(){
    grundy();
    int resp=0;
    for(int i=0; i<n; i++){
        resp^=g[v[i]];
    }
    //se resp==0, o primeiro perde
    return (resp!=0);
}
