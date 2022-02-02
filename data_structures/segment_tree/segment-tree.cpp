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
            buildUtil(arr, 0, arr_size - 1, 0);
        }

        T query(int i, int j){
            queryUtil(i, j, 0, arr_size-1, 0)
        }

        T update(int i, int j, T value){
            updateUtil(i, j, 0, arr_size-1, 0, value)
        }

    private:
        T buildUtil(vector<T> const &arr, int left, int right, int root){
            if(left == right){
                tree[root] = arr[left];
                return arr[left];
            }
            
            tree[root] = buildUtil(arr, left, MID(left, right), LEFT(root)) + buildUtil(arr, MID(left,right) + 1, right, RIGHT(root));
            return tree[root];
        }

        T queryUtil(int i, int j, int left, int right, int node){
            //total overlap
            if(i < left && j > right){
                return tree[node];
            }
            // no overlap
            else if(j < left || i > right){
                return 0;
            }
            // partial overlap
            else{
                return queryUtil(i, j, left, MID(left, right), LEFT(node)) + 
                    queryUtil(i, j, MID(left, right) + 1, right, RIGHT(node));
            }
        }

        T updateUtil(int i, int j, int left, int right, int node, T value){
            //total overlap
            if(i < left && j > right){
                tree[node] += value;
                return tree[node]
            }
            // no overlap
            else if(j < left || i > right){

            }
            // partial overlap
            else{
                tree[node] = updateUtil(i, j, left, MID(left, right), LEFT(node), value) + 
                    queryUtil(i, j, MID(left, right) + 1, right, RIGHT(node), value);
            }
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
