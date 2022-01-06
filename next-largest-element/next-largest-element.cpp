#include <iostream>
#include <vector>
#include <stack>

void next_largest(std::vector<int> &A)
{
    std::stack<int> S;      // stack to store processed items
    int cur_greater;    // initialize next greater element to index 1
    S.push(A[0]);

    for(int i = 1; i < A.size(); i++)
    {
        cur_greater = A[i];
        while(!S.empty() && cur_greater > S.top())
        {
            std::cout << cur_greater << "\t";
            S.pop();
        }
        S.push(A[i]);
    }

    // empty the stack
    int size = S.size();
    for(int i = 0; i < size; i++)
    {
        S.pop();
        std::cout << -1 << "\t";
    }
}

int main(){
    int size;
    std::vector<int> arr = {};

    std::cout << "input array size" << std::endl;
    std::cin >> size;
    
    std::cout << "input array elements" << std::endl;
    for(int i = 0; i < size; i++)
    {
        int value; 
        std::cin >> value;
        arr.push_back(value);
        
    }

    next_largest(arr);
}