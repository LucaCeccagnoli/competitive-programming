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

        // remove from the front elements no longer in the window
        while ( (!Q.empty()) && Q.front() <= i-k ){ 
            Q.pop_front();
        }

        // remove from the back elements smaller than the current element
        while( (!Q.empty()) && A[i] >= A[Q.back()]){
            Q.pop_back();
        }

        // insert new item
        Q.push_back(i);

        // front of the queue is the max for the current window
        if (i >= k-1){
            max.push_back(A[Q.front()]);
        }
    }
    return max;
}

int main(){
    int arr_size;
    int window_size;
    vector<int> arr = {};

    std::cout << "input array size" << std::endl;
    std::cin >> arr_size;

    std::cout << "input array elements" << std::endl;
    for(int i = 0; i < arr_size; i++)
    {
        int value; 
        std::cin >> value;
        arr.push_back(value);
        
    }

    std::cout << "input window size" << std::endl;
    std::cin >> window_size;

    vector<int> max = sliding_window<int>(arr, window_size);
    for(int i = 0; i < max.size(); i++){
        cout << "max for window " << i << " : " << max[i] << endl;;
    }

}