#include <iostream>
#include <vector>

int main(){
    int num_test_cases = 0;
    std::cout << "number of tests cases ?" << std::endl; 
    std::cin >> num_test_cases;

    for(int t = 0; t < num_test_cases; t++){
        int size = 0;
        std::cout << "number of items in the array? " << std::endl;
        std::cin >> size;

        int sum = 0;
        int total_sum = size * (size + 1) / 2;

        std::cout << "insert the values in the array" << std::endl;
        for(int i = 1; i < size; i++){
            int item = 0;
            std::cin >> item;

            sum += item;
        }

        std::cout << "the missing element is: " << total_sum - sum << std::endl;
    }
}