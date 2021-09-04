/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct fenwick{
    vector<A> fenw;
    int n;
    fenwick(int length){
        fenw.resize(length);
        n = length - 1;
    }

    void modify_fenwick(int x, ll val){
        for(; x <= n; x += x & -x){
            fenw[x] += val;
        }
        return;
    }

    ll get_fenwick(int x){
        ll val = 0;
        for(; x > 0; x -= x & -x){
            val += fenw[x];
        }
        return val;
    }
};
