/*
    Programmer : Alexandru Olteanu
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
// #pragma GCC optimize("Ofast");
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
// #pragma GCC target("abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

ifstream in("input.txt");
ofstream out("output.txt");
#define cin in
#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

/* 
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SparseTable{
    
    vector<vector<A>> matrix;
    vector<A> array;
    SparseTable(int n){
        int max_log = 0, p = 1;
        while(p <= n){
            p <<= 1;
            ++max_log;
        }
        array.resize(n + 1);
        matrix.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            matrix[i].resize(max_log);
        }
    }
    A func(A a, A b){
        ll r = 0;
        while(b){
            r = a % b;
            a = b;
            b = r;
        }
        return a;      //Probably it needs changes
    }
    
    void build(int l, int r){
        int max_log = 0, p = 1;
        int n = r - l + 1;
        while(p <= n){
            p <<= 1;
            ++max_log;
        }
        for(int j = 0; j < max_log; ++j){
            for(int i = l; i <= r - (1 << j) + 1; ++i){
                if(j == 0){
                    matrix[i][j] = array[i];
                    continue;
                }
                matrix[i][j] = func(matrix[i][j - 1], matrix[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll get(A start, A finish){
        ll ans = -1;
        while(start <= finish){
            A dist = finish - start + 1;
            A power = 1, sum = 0;
            while(power <= dist){
                power <<= 1;
                ++sum;
            }
            --sum;
            power >>= 1;
            if(ans < 0){
                ans = matrix[start][sum];
            }
            else{
                ans = func(ans, matrix[start][sum]);
            }
            start += power;
        }
        return ans;
    }
};

ll a[maxn];

int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;
        cin>>n;
        SparseTable<ll> st(n);
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        for(int i = 2; i <= n; ++i){
            st.array[i - 1] = abs(a[i] - a[i - 1]);
        }
        st.build(1, n);
        int i = 1, j = 1;
        int cnt = 0;
        --n;
        while(i <= n){
            bool ok = 1;
            while(j <= n && ok){
                if(st.get(i, j) >= 2){
                    cnt = max(cnt, j - i + 1);
                    ++j;
                }
                else{
                    ok = 0;
                }
            }
            if(j > n)j = n;
            ++i;
            j = max(j, i);
        }
        cout<<cnt + 1<<'\n';

    }       


    return 0;
} 
