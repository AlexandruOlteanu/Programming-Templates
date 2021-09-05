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
        array.resize(n);
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    A function(A a, A b){
        return (a < b ? a : b);
    }

    void build_segment(int node, int l, int r){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build_segment(node * 2, l, mid);
        build_segment(node * 2 + 1, mid + 1, r);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    void push_segment(int node, int l, int r){
        if(lazy[node] != 0){
            tree[node] += lazy[node];
            if(l != r){
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        return;
    }

    void update_segment(int node, int l, int r, int L, int R, A val){
        push_segment(node, l, r);
        if(r < L || l > R)return;
        if(l >= L && r <= R){
            lazy[node] += val;
            push_segment(node, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        update_segment(node * 2, l, mid, L, R, val);
        update_segment(node * 2 + 1, mid + 1, r, L, R, val);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    A ask_segment(int node, int l, int r, int L, int R){
        push_segment(node, l, r);
        if(r < L || l > R) return infll;
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        A ask1 = ask_segment(node * 2, l, mid, L, R);
        A ask2 = ask_segment(node * 2 + 1, mid + 1, r, L, R);
        return function(ask1, ask2);
    }
};




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;cin>>n;
        SegmentTree<ll> st(n + 1);
        for(int i = 1; i <= n; ++i){
            cin>>st.array[i];
        }
        st.build_segment(1, 1, n);
        int k;cin>>k;
        for(int i = 1; i <= k; ++i){
            int a, b, c = 0;
            char x[100];
            cin>>a>>b;
            ++a, ++b;
            cin.getline(x, 100);
            int u = strlen(x);
            if(int(u > 1)){
                bool ok = 0;
                for(int j = 1; j < u; ++j){
                    if(x[j] == '-')ok = 1;
                    else c = c * 10 + (x[j] - '0');
                }
                if(ok)c = -c;
                if(a > b){
                    st.update_segment(1, 1, n, a, n, c);
                    st.update_segment(1, 1, n, 1, b, c);
                }
                else{
                    st.update_segment(1, 1, n, a, b, c);
                }
                continue;
            }
            ll cnt = infll;
            if(a > b){
                cnt = min(cnt, st.ask_segment(1, 1, n, a, n));
                cnt = min(cnt, st.ask_segment(1, 1, n, 1, b));
            }
            else{
                cnt = st.ask_segment(1, 1, n, a, b);
            }
            cout<<cnt<<'\n';
        }

    }
    return 0;
}
