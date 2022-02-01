#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int min_jumps(vector<int> arr){
    vector<int> s = vector<int>(arr.size(), -1);    // all elements inaccessible by default
    s[0] = 0;

    for(int i = 1; i < s.size(); i++){
        int j = i-1;
        while(j >= 0){
            // we can jump from A[j] to s[i]
            if(s[i] == -1){
                // inizialize element
                s[i] = s[j] + 1;
            }

            if(arr[j] >= i - j && s[j] + 1 < s[i]){
                s[i] = s[j] + 1;
            }
            j--;
        }
    }

    return *(s.end() - 1);
}

int main(){
    int el;
    string s;
    vector<int> arr;

    cout << "input array elements" << endl;

    getline(cin, s);
    stringstream ss(s);
    while(ss >> el){
        arr.push_back(el);
    }
    //cin.ignore();

    cout << "minimum number of jumps to reach the end of the array: " <<  min_jumps(arr) << endl;
}