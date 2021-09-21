using namespace std;
#include <iostream>
#include <deque>
#include <vector>

template<typename T>
vector<T> sliding_window(vector<int> const &A, int k){
    deque<T> Q; // stores indexes
    vector<T> max;

    max.reserve(A.size() -k + 1);

    for(int i = 0; i < A.size(); i++){
        while ( (!Q.empty()) && Q.front() <= i-k ){ // skip first k times
            Q.pop_front();
        }
        // insert item in queue
        Q.push_back(i);

        // remove items  from the back until we find one that is larger than the current
        while( (!Q.empty()) && A[i] >= A[Q.back()]){
            Q.pop_back();
        }

        // insert new item
        Q.push_back(i);

        if (i >= k-1){
            max.push_back(A[Q.front()]);
        }
    }
    return max;
}

int main(){
    vector<int> vec{1, 2, 3, 2, 1, 4, 5, 5};
    vector<int> max = sliding_window<int>(vec, 3);
    for(int i = 0; i < max.size(); i++){
        cout << "max for window " << i << " : " << max[i] << endl;;
    }

}