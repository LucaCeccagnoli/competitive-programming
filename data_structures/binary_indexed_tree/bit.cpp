#include <iostream>
#include <vector>

#include "bit.h"

// initialize array of length size + 1, all elements to 0
BIT::BIT(int size){
    tree = std::vector<int>(size + 1, 0);
}

// initialize from another array: same elements + fake node at the beginning
BIT::BIT(std::vector<int> const &arr){
    tree = std::vector<int>(arr.size() + 1);

    // initialize tree with array values
    for(int i = 1; i < tree.size(); i++){
        tree[i] = arr[i-1];
    }

    // sum successor elements
    for(int i = 0; succ(i) < tree.size(); i++){
        tree[succ(i)] += tree[i];
    }
};

int BIT::succ(int i){
    return i + ( i & -i);
}

int BIT::prev(int i){
    return i - (i & -i);
}

int BIT::sum(int index){
    int sum = 0; 
    while( index > 0){
        sum += tree[index];
        index = prev(index);
    }
    return tree[index];
}

void BIT::update(int index, int value){
    while ( index < tree.size()){
        tree[index] += value;
        index = succ(index);
    }
}