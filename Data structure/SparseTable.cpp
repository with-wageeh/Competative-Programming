struct  sparsetable{
    vector<ll>log;
    vector<vector<ll>>table;
    sparsetable(int n , vector<ll> &v){
        table.resize(n , vector<ll>(22));
        log.resize(n + 5);
        build(n , v);
    }
    ll merge (ll a , ll b){
        //min
        //max
        //gcd
        //lcm
        return min(a , b);
    }
    void build(int n , vector<ll> &v){
        for (int i = 0; i < n ; ++i) table[i][0] = v[i];

        for (int i = 1; i < 22 ; ++i)
            for (int j = 0; j + (1 << (i - 1)) < n  ; ++j)
                table[j][i] = merge(table[j][i - 1] , table[j + (1 << (i - 1))][i - 1]);

        for (int i = 2; i <= n ; ++i) log[i] = log[i / 2] + 1 ;
    }
    ll Query(int l , int r){ // O(1)
        int sz = r - l + 1;
        int jump = log[sz];
        return merge(table[l][jump] , table[r - (1 << jump) + 1][jump]);
    }
};
