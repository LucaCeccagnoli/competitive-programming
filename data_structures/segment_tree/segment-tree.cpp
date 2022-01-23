#include <vector>
#include "segment-tree.hpp"

SegmentTree::SegmentTree(std::vector<int> const &arr){
    int arr_size = arr.size();
    int tree_size = arr_size * 2 - 1;

    // insert leaf nodes from array
    for(int i = 0; i < arr_size; i++){
        tree[arr_size + i -1] = arr[i];
    }

    // calculate parents
    for(int i = arr_size - 2; i >= 0; i--){
        tree[i] = tree[2 * i + 1] + tree[2 * i + 1];
    }
}

void SegmentTree::update(int left, int right, int value){
    updateUtil(0, left, right, value);
}

void SegmentTree::update(int left, int right, int value){
    
}
