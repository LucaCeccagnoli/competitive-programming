#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MID(l,r) l + (r - l) / 2 
#define LEFT(i) 2 * i + 1
#define RIGHT(i) 2 * i + 2

// example of segment tree for prefix sums

template<typename T>
struct SegmentTree{
    public: 
        vector<T> tree;
        int arr_size, tree_size;

        SegmentTree(vector<T> const &arr){
            arr_size = arr.size();

            int height = (int) ceil(log2(arr_size));
            tree_size = 2 * pow(2, height) - 1;

            tree = vector<T>(tree_size, 0);
            build(arr, 0, arr_size - 1, 0);
        }
    private:
        T build(vector<T> const &arr, int left, int right, int root){
            if(left == right){
                tree[root] = arr[left];
                return arr[left];
            }
            
            tree[root] = build(arr, left, MID(left, right), LEFT(root)) + build(arr, MID(left,right) + 1, right, RIGHT(root));
            return tree[root];
        }
};

int main(){
    typedef int int_type;
    vector<int_type> arr{1, 3, 5, 7, 9, 11};
    SegmentTree<int_type> st = SegmentTree<int_type>(arr);

    for(int i = 0; i < st.tree_size; i++){
        cout << st.tree[i] << " ";
    }
    cout << endl;
}
