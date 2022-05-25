vector<pair<ll, int>> v[1002];
vector<ll> dist(1002, infll);
priority_queue<pll> q;

void build_dijkstra(int root){
    dist[root] = 0;
    q.push({0, root});
    while(!q.empty()){
        int u = q.top().se;
        q.pop();
        for(auto i:v[u]){
            if(dist[i.se] > dist[u] + i.fi){
                dist[i.se] = dist[u] + i.fi;
                q.push({-dist[i.se], i.se});
            }
        }
    }
    return;
}
