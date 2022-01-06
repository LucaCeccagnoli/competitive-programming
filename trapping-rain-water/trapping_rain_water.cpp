#include <iostream>
#include <vector>
#include <algorithm>    // max, min

int trapping_rainwater(std::vector<int> &heights)
{
    int size = heights.size();

    if(size < 3)
    {
        return 0;
    }

    int total_water = 0;
    std::vector<int> left_heights(size), right_heights(size);

    left_heights[0] = heights[0];
    right_heights[size-1] = heights[size-1];

    // calculate left heights
    for(int i  = 1; i < size; i++)
    {
        left_heights[i] = std::max(left_heights[i-1], heights[i]);
    }

    // calculate right heights
    for(int i = size - 2; i >= 0; i--)
    {
        right_heights[i] = std::max(right_heights[i+1], heights[i]);
    }

    // intersect
    for(int i = 0; i < size; i++)
    {   
        int water_level = std::min(left_heights[i], right_heights[i]);
        water_level -= heights[i];
        total_water += water_level;
    }

    return total_water;
}

int main(){
    int size;
    std::vector<int> heights = {};

    std::cout << "input number of blocks" << std::endl;
    std::cin >> size;
    
    std::cout << "input block heights" << std::endl;
    for(int i = 0; i < size; i++)
    {
        int value; 
        std::cin >> value;
        heights.push_back(value);
        
    }

    std::cout << "total trapped water: " << trapping_rainwater(heights) << std::endl;
}