int quicksort(int pri, int seg){
    //guardo na variável pivô o último elemento do intervalo
    int pivo=v[seg];

    int ult=pri-1;

    for(int i=pri; i<=seg; i++){
        //se o elemento atual for menor ou igual ao pivô, então acrescento 1 a "ult" e
        //troco os valores do elemento da posição atual e de "ult"
        if(v[i]<=pivo){
            ult++;
            swap(v[ult], v[i]);
        }
    }
    //retorno "ult"
    return ult;
}
int quickselect(int esq, int dir){
    //enquanto "esq" for menor do que "dir"
    while(esq<=dir){
        //pego a posição final do pivô
        int pos=quicksort(esq, dir);
        if(pos==k){
            //se a posição do pivõ for igual a K, então achamos o nosso elemento,
            //assim retorno ele
            return v[pos];

        }else if(pos>k){
            //se a posição do pivô for maior que K, então devemos fazer com que
            //a ultima posição do intervalo se torne "ult" menos 1
            dir=pos-1;

        }else{
            //se a posição do pivô for menor que K, então devemos fazer com que
            //a primeira posição do intervalo se torne "ult" mais 1
            esq=pos+1;
        }
    }
}
