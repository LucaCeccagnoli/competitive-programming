#include <iostream>
#include <set>

int main(){
    std::set<int> A{1,2,3,4,5};
    auto it_end = A.end();
    it_end = it_end--;
}