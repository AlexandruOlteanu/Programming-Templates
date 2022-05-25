const int inf = 2e9;
const ll maxn = 1e5 + 2;

vector<pair<int, int>> v[maxn];
vector<int> dist(maxn, inf);
priority_queue<pair<int, int>> q;
bool processed[maxn];

void build_dijkstra(int root){
    dist[root] = 0;
    q.push({0, root});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if (processed[u]) {
            continue;
        }
        processed[u] = true;
        for(auto i:v[u]){
            if (processed[i.second]) {
                continue;
            }
            if(dist[i.second] > dist[u] + i.first){
                dist[i.second] = dist[u] + i.first;
                q.push({-dist[i.second], i.second});
            }
        }
    }
    return;
}
