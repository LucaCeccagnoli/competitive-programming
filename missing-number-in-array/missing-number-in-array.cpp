using namespace std;
#include <iostream>

int main(){
    int num_test_cases = 0;
    cout << "number of tests cases ?" << endl; 
    cin >> num_test_cases;

    for(int t = 0; t < num_test_cases; t++){
        int size = 0;
        cout << "number of items in the array? " << endl;
        cin >> size;

        int sum = 0;
        int total_sum = size * (size + 1) / 2;

        cout << "insert the values in the array" << endl;
        for(int i = 1; i < size; i++){
            int item = 0;
            cin >> item;

            sum += item;
        }

        cout << "the missing element is: " << total_sum - sum << endl;
    }
}