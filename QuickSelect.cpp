int n, k, v[mxn];

int quicksort(int pri, int seg){
    int pivo=v[seg];

    int ult=pri-1;

    for(int i=pri; i<=seg; i++){
        if(v[i]<=pivo){
            ult++;
            swap(v[ult], v[i]);
        }
    }
    return ult;
}

int quickselect(int esq, int dir){
    while(esq<=dir){
        int pos=quicksort(esq, dir);
        if(pos==k){
            return v[pos];
        }else if(pos>k){
            dir=pos-1;

        }else{
            esq=pos+1;
        }
    }
}
