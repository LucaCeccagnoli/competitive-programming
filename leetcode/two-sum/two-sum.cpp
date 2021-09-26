#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int>complements{};
        
        for(int i= 0; i < nums.size(); i++){
            int num = nums[i];
            int complement = target - num;

            if( complements.find(num) != complements.end()){
                
                // a complement to nums[i] has been found, so their sum equals target
                return std::vector<int>{complements[num], i};
            }
            else{
                //add complement to map
                complements.insert({ complement, i }); //duplicate keys are not updated
            }
        }
        return std::vector<int>{-1};
    }

int main(){
    std::vector<int> nums{4, 9, 7, 3, 1, 1, 5, 4};
    int target = 14;

    std::vector<int> result = twoSum(nums, target);
    for(int i = 0; i <= result.size() ; i++){
        std::cout << result[0] << " ";
    }
}