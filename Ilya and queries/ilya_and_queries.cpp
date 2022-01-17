#include <iostream>
#include <vector>

std::vector<int> build_prefix(std::vector<int> &A){
    std::vector<int> prefix_sum(A.size(), 0);        
    for(int i = 1; i < prefix_sum.size(); i++){
        if(A[i-1] == A[i]){
            prefix_sum[i] = prefix_sum[i-1] + 1;
        }
        else{
            prefix_sum[i] = prefix_sum[i-1];
        }
    }

    return prefix_sum;
}

int query(std::vector<int>&P ,int start, int end){
    return P[end] - P[start];
}

int main(){
    int size;
    std::vector<int> bin_arr;

    std::cout << "input array size" << std::endl;
    std::cin >> size;
    std::cout << "input binary array of 0s and 1s" << std::endl;
    for(int i = 0; i < size; i++)
    {
        int value;
        std::cin >> value;
        if(value != 0 && value != 1)
        {
            std::cout << "can only input 0 or 1" << value << std::endl;
            i--;
            continue;
        }
        bin_arr.push_back(value);
    }

    // initialize prefix sum array
    std::vector<int> prefix_sum_arr = build_prefix(bin_arr);

    int query_count, left, right;
    std::cout << "input number of queries" << std::endl;
    std::cin >> query_count;

    std::cout << "input query pairs: left and right index of the array" << std::endl;
    for(int i = 0; i < query_count; i++)
    {
        std::cin >> left >> right;

        if (left < 0 || left >= size)
        {
            std::cout << "invalid left index" << std::endl;
            i--;
            continue;
        }
        else if (right < 0 || right >= size || right < left)
        {
            std::cout << "invalid right index" << std::endl;
            i--;
            continue;
        }
        else
        {
            // run query
            std::cout << "number of equal consecutive elements: " << query(prefix_sum_arr, left, right) << std::endl;
        }
    }
    return 0;
}