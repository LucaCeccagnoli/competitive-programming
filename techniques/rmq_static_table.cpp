#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int previous_power(int x){
    return 1U << (int)log2(x);
}

int query(int left, int right, vector<vector<int>> &lookup){
    // find closest first power of two lower than right - left
    // CHAR_BIT = 8
    int lg = previous_power(right - left);
    return min(lookup[left][log2(lg)], lookup[right - lg][log2(lg)]);
}

int main(){
    vector<int> arr = {7, 2, 3, 0, 5, 10, 3, 12, 18};

    int rows = arr.size();
    int columns = log2(rows) + 1;    

    vector<vector<int>> lookup = 
        vector<vector<int>>(
            rows, 
            vector<int>(columns)
        );

    // initialize -> O(nlogn)
    for(int r = 0; r < rows; r++){
        lookup[r][0] = r;
    }
    for(int c = 1; c < columns; c++){
        for(int r = 0; r < rows - pow(2,c); r++){
            int i1, i2;
            i1 = lookup[r + 0][c-1];
            i2 = lookup[r + pow(2,c)-1][c-1];

            lookup[r][c] = arr[i1] < arr[i2] ? i1 : i2;
        }
    }

    cout << "rmq(2,7) = " << query(0,2,lookup) << endl;
}