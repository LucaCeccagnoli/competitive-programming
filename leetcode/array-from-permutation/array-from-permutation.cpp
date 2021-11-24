#include<iostream>
#include<vector>

std::vector<int> array_from_permutation(std::vector<int> const &A){
    std::vector<int> ans(A.size(), 0);  // initialize with zeros

    for(int i=0; i < A.size(); i++){
        ans[i] = A[A[i]];
    }
    return ans;
}

std::vector<int> array_from_permutation_in_place(std::vector<int> &A){
    // hard, still have to implement
    return A;
}

int main(){
    std::vector<int> A{5,0,1,2,3,4};
    std::vector<int> ans = array_from_permutation(A);
    
    for(int i = 0; i < ans.size(); i++){
        //std::cout << ans[i] << std::endl;
    }

    array_from_permutation_in_place(A);
    for(int i = 0; i < ans.size(); i++){
        std::cout << A[i] << std::endl;
    }
}