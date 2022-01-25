#include <vector>
#include <iostream>
#include <cmath>

std::vector<int> build_tree(std::vector<int>const &arr){
    int arr_size = arr.size();
    int tree_size = arr_size * 2 - 1;
    std::vector<int> tree(tree_size, 0);

    for(int i = 0; i < arr_size; i++){
        tree[i + arr_size] = arr[i];
    }

    for(int i = arr_size - 1; i >= 0; i--){
        tree[i] = std::min(tree[i*2], tree[i*2 + 1]);
    }

    return arr;
}

void sum(std::vector<int> &tree, int index, int value){
    index = index * 2 + 1;
    while(index >= 0){
        tree[index] += value;
        index = index / 2;
    }
}

int rmq(std::vector<int> &tree, int start, int end){
    return rmq_util(tree, start, end, 0, tree.size() -1, 0);
}

int rmq_util(std::vector<int> &tree, int start, int end, int left, int right, int index){
    // full overlap
    if(start <= left && end >= right){
        return index;
    }
    // partial overlap
    else if(start <= left || end >= right){
        int left = rmq_util(tree, start, end, left, right/2, index*2 + 1);
        int right = rmq_util(tree, start, end, left, right/2, index*2 + 1);
        return tree[left] < tree[right] ? left : right;
    }
    else{
        // return index of parent
        return index*2;
    }
}

int main(){
    std::vector<int> arr{1,2,3};
    build_tree(arr);
}