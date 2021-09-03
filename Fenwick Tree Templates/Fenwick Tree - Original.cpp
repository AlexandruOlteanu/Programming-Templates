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

//#define cin in
//#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

ll a[maxn], res[maxn];

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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            modify_fenwick(i, n, i - 1);
        }
        for(int i = n; i >= 1; --i){
            int lo = 1, hi = n;
            while(lo <= hi){
                int mid = lo + (hi - lo) / 2;
                if(get_fenwick(mid) > a[i]){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            --lo;
            res[i] = lo;
            modify_fenwick(lo + 1, n, -lo);
        }
        for(int i = 1; i <= n; ++i){
            cout<<res[i]<<" ";
        }

    }
    return 0;
}
