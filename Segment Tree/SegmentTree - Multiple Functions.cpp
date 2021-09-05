/*
    Programmer : Alexandru_Olteanu
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ifstream in("input.txt");
ofstream out("output.txt");
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

#define cin in
#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 1e5 + 2;

/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SegmentTree{
    vector<A> array;
    vector<A> tree;
    vector<A> lazy;

    SegmentTree(int n){
        array.resize(n, 0);
        tree.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }

    A function(A a, A b, int p){
        if(p == 1) return (a > b ? a : b);
        return (a < b ? a : b);
    }

    void build_segment(int node, int l, int r, int p){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build_segment(node * 2, l, mid, p);
        build_segment(node * 2 + 1, mid + 1, r, p);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1], p);
        return;
    }

    void push_segment(int node, int l, int r, int p){
        return;
        if(lazy[node] != 0){
            tree[node] = (r - l + 1) - tree[node];
            if(l != r){
                lazy[node * 2] ^= 1;
                lazy[node * 2 + 1] ^= 1;
            }
            lazy[node] = 0;
        }
        return;
    }

    void update_segment(int node, int l, int r, int L, int R, int p){
        push_segment(node, l, r, p);
        if(r < L || l > R)return;
        if(l >= L && r <= R){
            lazy[node] ^= 1;
            push_segment(node, l, r, p);
            return;
        }
        int mid = l + (r - l) / 2;
        update_segment(node * 2, l, mid, L, R, p);
        update_segment(node * 2 + 1, mid + 1, r, L, R, p);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1], p);
        return;
    }

    A ask_segment(int node, int l, int r, int L, int R, int p){
        push_segment(node, l, r, p);
        if(r < L || l > R){
            if(p == 1)return -infll;
            else return infll;
        }
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        A ask1 = ask_segment(node * 2, l, mid, L, R, p);
        A ask2 = ask_segment(node * 2 + 1, mid + 1, r, L, R, p);
        return function(ask1, ask2, p);
    }
};

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, k;
        cin>>n>>k;
        SegmentTree<ll> maxi(n + 1), mini(n + 1);
        for(int i = 1; i <= n; ++i){
            cin>>maxi.array[i];
        }
        for(int i = 1; i <= n; ++i){
            int x;cin>>x;
            maxi.array[i] = x - maxi.array[i];
            maxi.array[i] += maxi.array[i - 1];
            mini.array[i] = maxi.array[i];
        }
        maxi.build_segment(1, 1, n, 1);
        mini.build_segment(1, 1, n, 0);
        for(int i = 1; i <= k; ++i){
            int x, y;cin>>x>>y;
            if(maxi.array[y] - maxi.array[x - 1] != 0){
                cout<<"-1\n";
                continue;
            }
            ll cnt = maxi.ask_segment(1, 1, n, x, y, 1);
            ll cnt1 = mini.ask_segment(1, 1, n, x, y, 0);
            cnt -= maxi.array[x - 1];
            cnt1 -= maxi.array[x - 1];
            if(cnt1 < 0){
                cout<<"-1\n";
                continue;
            }
            cout<<cnt<<'\n';
        }



    }
    return 0;
}
