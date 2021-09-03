vector<pair<ll, int> v[maxn];
int p[maxn];
vector<tuple<ll, int, int>> e;

int find(int x){
    return ((x == p[x]) ? x : (p[x] = find(p[x])));
}

void merge(int x, int y){
    p[x] = y;
}

void SpanningTree(int n){
 
    for(int i = 0; i < n; ++i){
        int x = find(get<1>(e[i]));
        int y = find(get<2>(e[i]));
        ll cost = get<0>(e[i]);
        if(x == y)continue;
        v[get<1>(e[i])].pb({cost, get<2>(e[i])});
        v[get<2>(e[i])].pb({cost, get<1>(e[i])});
        unite(x, y);
    }
 
    return;
}
