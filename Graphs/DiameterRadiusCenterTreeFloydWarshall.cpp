int n, dist[mxn][mxn], excen[mxn];

    int diam=-1, radius=INF;

    vector<int>center;

    memset(dist, INF, sizeof(dist));

    memset(excen, -1, sizeof(excen));

    for(int v=0; v<n; v++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][v]+dist[v][j]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            excen[i]=max(excen[i], dist[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        radius=min(radius, excen[i]);
        diam=max(diam, excen[i]);
    }

    for(int i=0; i<n; i++){
        if(radius==excen[i]){
            center.push_back(i);
        }
    }
