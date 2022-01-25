#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(){
    std::vector<int> A{4, 8, 1, 2, 6, 15, 10, 11};    // original
    int size = A.size();
    std::vector<int> S = A;     // copy to sort
    std::vector<int> C(size);   // compressed coordinates

    //sort vector
    std::sort(S.begin(), S.end());

    for(int i = 0; i < size; i++){
        // pointer to the position of the original element in the sorted array

        // TODO: this takes values, need indexes
        auto ref = std::lower_bound(A.begin(), A.end(), i);

        std::cout << *ref << std::endl;

        auto a = A.begin();
        auto ptr_S = (int) (std::lower_bound(S.begin(), S.end(), i) - S.begin());

        // original element's position equal to the position of its pointer in the sorted array
        //C[i] = A[ptr_S];
        //int a = 1;
    }

    std::cout << "old array: " << std::endl;
    for(int i = 0; i < size; i++){
         std::cout << A[i] << " ";
    }

    std::cout << "sorted: " << std::endl;
    for(int i = 0; i < size; i++){
         std::cout << S[i] << " ";
    }

    std::cout << "array with every element replaced by its rank: " << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << C[i] << " ";
    }
}