#include <iostream>
#include <vector>
#include <set>

int main(){
    std::vector<std::vector<int>> measurements{
        {7,3,3},
        {4,2,-1},
        {1,1,2}
    };

    std::set<std::vector<int>> ordered_measurements{};

    for(int i = 0; i < measurements.size(); i++){
        ordered_measurements.insert(measurements[i]);
    }
    
    return 0;
}