#include <iostream>
#include <vector>

int calc_min_jump_strength(std::vector<int> &tree){
    int min_strength = 0;
    for(int i=tree.size() - 1; i > 0; i--)
    {
        if(min_strength < tree[i] - tree[i-1])
        {
            min_strength = tree[i] - tree[i-1];
        }
        else if(min_strength == tree[i] - tree[i-1])
        {
            // found the same height twice: need to add 1 to min strength
            min_strength++;
        }
    }
    return min_strength;
}

int main(){
    int size, current_rung = 0;

    std::cout << "input number of rungs in the tree" << std::endl;
    std::cin >> size;

    std::vector<int> tree(size);

    std::cout << "input heights of each rung" << std::endl;
    while(current_rung < size)
    {
        int height;
        std::cin >> height;

        // first rung can have any height
        if(current_rung == 0)
        {
            tree[current_rung] = height;
            current_rung++;
            continue;
        }
        else if(height < tree[current_rung-1])
        {
            // can't input and height lower than the previous one
            std::cout << "new rung has to be higher than the last one" << std::endl;
        }
        else
        {
            tree[current_rung] = height;
            current_rung++;
        }
    }

    std::cout << "minimum jump strenght is: " << calc_min_jump_strength(tree) << std::endl;;
}