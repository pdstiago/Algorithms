// Can find max XOR subset
int base[32];
void insert(int mask){
    for(int i=20; i>=0; i--){
        if(mask & (1<<i)){
            if(!base[i]){
                base[i] = mask;
                return;
            }
            mask^=base[i];
        }
    }
}

int query(){
    int ans = 0;
    for(int i=20; i>=0; i--){
        if(!base[i]) continue;

        if(ans & (1<<i)) continue;

        ans^=base[i];
    }
    return ans;
}
