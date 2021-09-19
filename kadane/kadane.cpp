using namespace std;
#include <iostream>

// suboptimal
int check_all_subarrays(int size, int arr[]) {
    int max_sum = arr[0];

    // try subarrays of all sizes
    for (int n = 1; n <= size + 1; n++){             
        for(int i = 0; i < size + 1 - n; i++){  

            int cur_sum = 0;           
            for(int j = i; j < i + n; j++ ){   
                cur_sum += arr[j];
            }
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
        }
    }
    return max_sum;
}

// optimal
int kadanes(int size, int arr[]){
    int accumulator = 0;
    int current_max = INT32_MIN;

    for(int i = 0; i < size; i++){
        // collect the sum of the current subarray
        accumulator += arr[i];

        if (accumulator < arr[i]){
            // The new value is better than the sum of the current subarray, so start a new one from here
            accumulator = arr[i];
        }

        if (current_max < accumulator){
            current_max = accumulator;
        }
    }
    return current_max;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "check all subarrays: " <<check_all_subarrays(size, arr) << endl;
    cout << "Kadane's algorithm: " << kadanes(size, arr) << endl;

    return 0;
}