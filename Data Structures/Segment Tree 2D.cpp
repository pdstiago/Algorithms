struct Seg2D{ //0-indexed / O(log^2(N))
    int n, m, neutral=-INF;
    vector<vector<int> > tree;

    Seg2D(int n, int m) : n(n), m(m), tree(2*n, vector<int>(2*m)) {}

    int join(int a, int b){
        return max(a, b);
    }

    void upd(int x, int y, int val){
        x+=n, y+=m;
        tree[x][y]=val;
        for(int j=y/2; j>0; j/=2){
            tree[x][j]=join(tree[x][2*j], tree[x][2*j+1]);
        }
        for(x/=2; x>0; x/=2){
            tree[x][y]=join(tree[2*x][y], tree[2*x+1][y]);
            for(int j=y/2; j>0; j/=2){
                tree[x][j]=join(tree[x][2*j], tree[x][2*j+1]);
            }
        }
    }

    vector<int> getcover(int l, int r, int k){
        l=max(0, l);
        r=min(k, r);
        vector<int> ans;
        for(l+=k, r+=k; l<r; l/=2, r/=2){
            if(l&1) ans.push_back(l++);
            if(r&1) ans.push_back(--r);
        }
        return ans;
    }

    int query(int x1, int y1, int x2, int y2){
        auto c1 = getcover(x1, x2+1, n);
        auto c2 = getcover(y1, y2+1, m);
        int ans=neutral;
        for(auto i:c1){
            for(auto j:c2){
                ans=join(ans, tree[i][j]);
            }
        }
        return ans;
    }
};
