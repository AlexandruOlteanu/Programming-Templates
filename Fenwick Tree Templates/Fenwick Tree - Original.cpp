/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct FenwickTree{
    vector<A> fenwick;
    int n;
    FenwickTree(int length){
        fenwick.resize(length);
        n = length - 1;
    }

    void modify_fenwick(int x, ll val){
        for(; x <= n; x += x & -x){
            fenwick[x] += val;
        }
        return;
    }

    ll get_fenwick(int x){
        ll val = 0;
        for(; x > 0; x -= x & -x){
            val += fenwick[x];
        }
        return val;
    }
};
