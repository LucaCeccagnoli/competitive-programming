#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

// insert a new key or increment an existing one, returning its value
int key_insert_increment( std::unordered_map<int, int> &M, int key){
    // if key is not present, insert it
    if (M.find(key) == M.end()){
        M[key] = 1;
    }
    else{
        M[key]++;
    }
    return M[key];
}

// decrement an existing key, return its value and remove it if it is 0
int key_decrement_remove( std::unordered_map<int, int> &M, int key){
    // if key is not present, return 0
    if (M.find(key) == M.end()){
        return 0;
    }
    else{
        // decrement key, if its value reaches 0, remove it and return 0
        M[key]--;
        if (M[key] == 0){
            M.erase(key);
            return 0;
        }
    }
    return M[key];
}


std::tuple<int, int> find_longest_k_good(std::vector<int> &A, int k){
    // save the number of occurrencies of a key
    std::unordered_map<int, int> K{};

    int max_length = 0;
    int max_head = 0;
    int max_tail = 0;

    for(int head = 0, tail = 0; head < A.size(); head++){
        // if key is already present or there are still < k keys
        if ( !(K.find(A[head]) == K.end()) || (K.find(A[head]) == K.end()) && (K.size() < k) ){
                int length = head - tail + 1; 
                if (length > max_length){
                    max_length = length;
                    max_head = head;
                    max_tail = tail;
                }
        }
        // found an item that invalidates the current subarray
        else{
            // move tail forward until an item no longet occurs in the current array
            do{
                tail++;
            }while(key_decrement_remove(K, A[tail - 1]) > 0);
        }
        key_insert_increment(K, A[head]);
    }

    std::tuple<int, int> result{max_tail, max_head};
    return result;
}

int main(){
    std::vector<std::tuple<std::vector<int>, int>> test_cases{
        {{6, 5, 1, 2, 3, 2, 1, 4, 5}, 3},   // (2,6)
        {{1, 1, 2, 3, 3, 4, 4, 4, 1, 3, 2, 3}, 3},   // (3,9)
        {{1, 2, 3, 4, 5}, 5}, // (0,4)
        {{1, 2, 3}, 1}  // (0, 0)
    };
    
    for(int i = 0; i < test_cases.size(); i++){
        std::tuple<int, int> result = find_longest_k_good(std::get<0>(test_cases[i]), std::get<1>(test_cases[i]));
        std::cout << std::get<0>(result) << " " << std::get<1>(result) << std::endl;
    }
}

