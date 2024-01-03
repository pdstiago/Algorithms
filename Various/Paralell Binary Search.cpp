int l[mxn], r[mxn], resp[mxn];
vector<int> meio[mxq];

void build(){
    //remember to check l and r limits (maybe l can be 0)
    for(int i=0; i<n; i++){
        l[i]=1, r[i]=q, resp[i]=-1;
    }
}

void bb(){
    int ok=1;
    while(ok){
        ok=0;
        //restart the structure
        for(int i=0; i<n; i++){
            if(l[i]<=r[i]) meio[(l[i]+r[i])>>1].pb(i);
        }
        for(int i=1; i<=q; i++){
            //do the current update
            while(!meio[i].empty()){
                ok=1;
                int k = meio[i].back();
                meio[i].pop_back();
                if(/*check condition*/){
                    resp[k]=i;
                    r[k]=i-1;
                }else{
                    l[k]=i+1;
                }
            }
        }
    }
}