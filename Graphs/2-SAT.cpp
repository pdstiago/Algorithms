//use kosaraju struct
// i for '+' / i+m for '-'
void add_edge(int x, int sx, int y, int sy){
    // int a, b, c1, c2;
    // char sa, sb;
    // cin >> sa >> a >> sb >> b;

    // (+ 2 - 1) quero topping 2, mas não quero o 1
    // f = (x1 ou y1) e ... (xn ou yn), se f == 1, então é possível
    // (x1 ou y1) = x1 -> ~y1 = y1 -> ~x1
    // se x1 e ~x1 estiverem na mesma scc é impossível

    // c1=(sa=='+'?1:0);
    // c2=(sb=='+'?1:0);

    // kosa.add_edge(a, c1, b, c2);
    
    sx^=1, sy^=1;
    
    vec[x+m*sx].push_back(y+m*(!sy));
    vec[y+m*sy].push_back(x+m*(!sx));
 
    rvec[y+m*(!sy)].push_back(x+m*sx);
    rvec[x+m*(!sx)].push_back(y+m*sy);
}
void build(){
    //use normal build of kosaraju to find the components, remeber number of nodes is 2*m
    
    int can=1;
    for(int i=1; i<=m; i++){
        if(comp[i]==comp[i+m]) can=0;
        resp[i]=comp[i]<comp[i+m]?'+':'-';
    }
    if(can){
        cout << "YES" << endl;
        for(int i=1; i<=m; i++){
            cout << resp[i] << " ";
        }
    }else{
        cout << "NO" << endl;
    }
}
