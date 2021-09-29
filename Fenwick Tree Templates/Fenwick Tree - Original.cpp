/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct FenwickTree{
    vector<A> array;
    int n;
    FenwickTree(int length){
        array.resize(length + 1);
        n = length - 1;
    }

    void modify(int x, ll val){
        for(; x <= n; x += x & -x){
            fenwick[x] += val;
        }
        return;
    }
    
    ll calc(int x){
        ll val = 0;
        for(; x > 0; x -= x & -x){
            val += array[x];
        }
        return val;
    }
    
    ll get(int l, int r){
        return calc(r) - calc(l - 1);   
    }
};
