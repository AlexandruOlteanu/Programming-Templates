/*
    Template created by Alexandru Olteanu
*/
vector<pair<ll, int>> graph[maxn];
int p[maxn];
template<typename A>
struct SpanningTree {

    vector<tuple<A, int, int>> edge;

    int find(int x){
        if(!p[x])return (p[x] = x);
        return ((x == p[x]) ? x : (p[x] = find(p[x])));
    }

    void merge(int x, int y){
        p[x] = y;
        return;
    }

    void push_graph(A cost, int first, int second){
        tuple<A, int, int> l;
        l = {cost, first, second};
        edge.pb(l);
        return;
    }
    void build_tree(){
        sort(all(edge));
        ll n = (ll)edge.size();
        for(ll i = 0; i < n; ++i){
            int x = find(get<1>(edge[i]));
            int y = find(get<2>(edge[i]));
            A cost = get<0>(edge[i]);
            if(x == y)continue;
            graph[get<1>(edge[i])].pb({cost, get<2>(edge[i])});
            graph[get<2>(edge[i])].pb({cost, get<1>(edge[i])});
            merge(x, y);
        }
 
        return;
    }
};
