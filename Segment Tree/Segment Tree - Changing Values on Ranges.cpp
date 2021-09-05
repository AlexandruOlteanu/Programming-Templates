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
