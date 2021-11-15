/* 
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SquareRootDecomposition{

    vector<A> array;
    vector<A> tree;
    A block_size;

    SquareRootDecomposition(int n){
        block_size = sqrt(n) + (sqrt(n) != (int)sqrt(n));
        array.resize(n + 1);
        tree.resize(block_size + 1);
    }

    A func(A a, A b){
        if(a < b){
            return a;
        }
        else{
            return b;
        }
    }

    void build(int n){
        for(int i = 1; i <= n; ++i){
            int rest = (i % block_size != 0);
            tree[i / block_size + rest] = array[i];
        }
        for(int i = 1; i <= n; ++i){
            int rest = (i % block_size != 0);
            tree[i / block_size + rest] = func(tree[i / block_size + rest], array[i]);
        }
        return;
    }

    A get(int l, int r){
        A ans = array[l];
        for(int i = l; i <= r; ++i){
            if(i % block_size == 1 && i + block_size - 1 <= r){
                ans = func(minimum, tree[i / block_size + 1]);
                i += (block_size - 1);
            }
            else{
                ans = func(minimum, array[i]);
            }
        }

        return ans;  
    }

};
