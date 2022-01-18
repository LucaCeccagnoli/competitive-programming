#include <iostream>
#include <vector>
#include <numeric>

int number_of_ways_3(std::vector<int> arr){
    // sum all elements in the array and compute prefix sum
    int sum = arr[0], size = arr.size(), sub_sum = 0, number_of_ways = 0;
    std::vector<int> prefix(arr.size(), sum);

    for(int i = 1; i < size; i++){
        prefix[i] = prefix[i-1] + arr[i]; 
    }
    sum = prefix[size-1];
    sub_sum = sum/3;

    // find indexes of the first and last segment
    int first = -1, last = -1;
    for(int i = 0; i < size; i++){
        // first element that sums up to sub_sum
        if(first == -1 && prefix[i] == sub_sum){
            first = i + 1;
        }
        // last element that sums up to sum-sub_sum
        else if(prefix[i-1] == sum - sub_sum){
            last = i;
        }
    }

    // compute number of ways
    int i = first, j = 0, comb = 1;
    while(i < last){
        if( prefix[i] % sub_sum == 0){
            int cur_value = prefix[i];
            while( prefix[i] == cur_value){
                number_of_ways += comb;     // combinations
                i++;
            }
            comb = number_of_ways;
        }
        i++;   
    }
    return number_of_ways;
}

int main(){
    int size, val;
    std::vector<int> arr;
    std::cout << "input array size" << std::endl;
    std::cin >> size;

    std::cout << "input array elements" << std::endl;
    for(int i = 0; i < size; i++){
        std::cin >> val;
        arr.push_back(val);
    }

    std::cout << "number of ways you can split the array in 3: "<< number_of_ways_3(arr) << std::endl;
}