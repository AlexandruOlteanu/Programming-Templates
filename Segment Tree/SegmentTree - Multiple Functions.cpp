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
        if(p == 1) return (a > b ? a : b); //Probably it needs changes
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
        if(lazy[node] != 0){
            if(l != r){
                tree[node] = function(tree[node * 2], tree[node * 2 + 1], p); //Probably it needs changes
                lazy[node * 2] ^= 1;
                lazy[node * 2 + 1] ^= 1;
            }
            else{
                tree[node] = array[l];
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
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if(mid < L){
            return ask_segment(node * 2 + 1, mid + 1, r, L, R, p);
        }
        if(mid >= R){
            return ask_segment(node * 2, l, mid, L, R);
        }
        return function(ask_segment(node * 2, l, mid, L, R), ask_segment(node * 2 + 1, mid + 1, r, L, R, p));
    }
};
