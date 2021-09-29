/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SegmentTree{
    vector<A> array;
    vector<A> tree;
    vector<A> lazy;

    SegmentTree(int n){
        array.resize(n + 1);
        tree.resize(4 * (n + 1) + 1);
        lazy.resize(4 * (n + 1) + 1);
    }

    A func(A a, A b, int p){
        return (a < b ? a : b);     //Probably it needs changes
    }

    void build(int node, int l, int r, int p){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2, l, mid, p);
        build(node * 2 + 1, mid + 1, r, p);
        tree[node] = func(tree[node * 2], tree[node * 2 + 1], p);
        return;
    }

    void push(int node, int l, int r, int p){
        if(lazy[node] != 0){
            tree[node] += lazy[node];      //Probably it needs changes
            if(l != r){
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
        return;
    }

    void update(int node, int l, int r, int L, int R, A val, int p){
        push(node, l, r, p);
        if(r < L || l > R)return;
        if(l >= L && r <= R){
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        update(node * 2, l, mid, L, R, val, p);
        update(node * 2 + 1, mid + 1, r, L, R, val, p);
        tree[node] = func(tree[node * 2], tree[node * 2 + 1], p);
        return;
    }

    A get(int node, int l, int r, int L, int R, int p){
        push(node, l, r, p);
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if(mid < L){
            return get(node * 2 + 1, mid + 1, r, L, R, p);
        }
        if(mid >= R){
            return get(node * 2, l, mid, L, R, p);
        }
        return func(get(node * 2, l, mid, L, R, p), get(node * 2 + 1, mid + 1, r, L, R, p), p);
    }
};
