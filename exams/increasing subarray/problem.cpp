#include <vector>
#include <iostream>

using namespace std;

typedef uint64_t intT;

int solve(vector<intT> A){
    int max_length = 0; // max length found for the array
    int change = -1;     // index of the element that can be changed
    int l = 0, r = 1;   // two pointers

    while(l < A.size() && r < A.size()){
        if(A[r] <= A[r-1]){
            // if there is already an element to change
            // bring l forward until its position
            if(change != -1){
                l = change;
            }
            change = r;
        }

        // check current length
        if(r - l + 1 > max_length){
            max_length = r - l + 1;
        }
        r++;
    }
    return max_length;
}

int main(){
    intT size, el;

    cin >> size;

    vector<intT> A;

    for(intT i = 0; i < size; i++){
        cin >> el;
        A.push_back(el);
    }
    cin.ignore();

    cout << solve(A) << endl;
}