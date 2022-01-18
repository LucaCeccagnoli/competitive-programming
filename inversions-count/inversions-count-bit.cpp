#include <iostream>
#include <vector>
#include <map>
#include "data-tructures/BIT/bit.hpp"

std::vector<int> coordinate_compression(std::vector<int> arr){      //copy value
    int count = 0;
    std::map<int, int> compressed;

    for (int i: arr){
        compressed[i];      // equals compressed[i] = arr[i]
    }

    for(auto &i: compressed){      // reference to pair
        i.second = count++;      // equals compressed[i] = count++;
    }

    for(int &i: arr){
        i = compressed[i];   //equals arr[i] = compressed[i]
    }

    return arr;
}

int inv_count(std::vector<int> &arr){
    int inversions = 0;
    std::vector<int> compressed_arr = coordinate_compression(arr);
    BIT bit(arr.size());

    for(int i = compressed_arr.size() - 1; i >= 0; i-- ){
        bit.tree[compressed_arr[i]] = 1;
        inversions += bit.sum(i-1);
    } 
}

int main(){
    int size, value;
    std::vector<int> arr;

    std::cout << "input array size" << std::endl;
    std::cin >> size;

    std::cout << "input array elements" << std::endl;
    for(int i = 0; i < size; i++)
    {
        std::cin >> value;
        arr.push_back(value);   
    }

    std::cout << "number of inversions: " << inv_count(arr) << std::endl;
}