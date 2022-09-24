pascal[0][0]=1;
for(int i=1; i<=n; i++){
    pascal[i][0]=pascal[i][i]=1;
    for(int j=1; j<i; j++){
        pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
    }
}