using namespace std;
#include <iostream>

void leaders(int length, int arr[]){
    // rightmost element is always a leader
    int highest = arr[length - 1];
    cout << highest << " ";

    // iterate array backwards
    for(int i = length-2; i >= 0; i--){
        
        if(arr[i] > highest){
            highest = arr[i];
            cout << highest << " ";
        }
    }
    cout << endl;
}

int main(){
    int arr[] = {16, 17, 4, 3, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]); // obtain number of items   

    leaders(size, arr);

    return 0;
}