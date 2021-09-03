/*
    Template created by Alexandru Olteanu
*/
ll fenw[maxn];
void modify_fenwick(int x,int n, ll val){
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

