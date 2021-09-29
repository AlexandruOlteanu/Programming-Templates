/* 
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SparseTable{
    
    vector<vector<A>> matrix;
    vector<A> array;
    SparseTable(int n){
        int max_log = 0, p = 1;
        while(p <= n){
            p <<= 1;
            ++max_log;
        }
        array.resize(n + 1);
        matrix.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            matrix[i].resize(max_log);
        }
    }
    A func(A a, A b, int p){
        if(p == 1) return min(a, b);
        return max(a, b);    //Probably it needs changes
    }
    
    void build(int l, int r, int p){
        int max_log = 0, power = 1;
        int n = r - l + 1;
        while(power <= n){
            power <<= 1;
            ++max_log;
        }
        for(int j = 0; j < max_log; ++j){
            for(int i = l; i <= r - (1 << j) + 1; ++i){
                if(j == 0){
                    matrix[i][j] = array[i];
                    continue;
                }
                matrix[i][j] = func(matrix[i][j - 1], matrix[i + (1 << (j - 1))][j - 1], p);
            }
        }
    }

    ll get(A start, A finish, int p){
        ll ans = 0;
        bool ok = 1;
        while(start <= finish){
            A dist = finish - start + 1;
            A power = 1, sum = 0;
            while(power <= dist){
                power <<= 1;
                ++sum;
            }
            --sum;
            power >>= 1;
            if(ok){
                ans = matrix[start][sum];
                ok = 0;
            }
            else{
                ans = func(ans, matrix[start][sum], p);
            }
            start += power;
        }
        return ans;
    }
};
