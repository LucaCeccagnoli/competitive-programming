using namespace std;
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

int merge_inversions(vector<int>&A, int const left, int const mid, int const right){
    int l = left;           // part of the array to be analyzed
    int r = mid + 1;

    vector<int> sorted_array; 

    int incr = 0;           // 
    int inversions = 0;

    while ( l <= mid && r <= right)
    {
        if (A[l] > A[r]){             
            sorted_array.push_back(A[r]);
            r++;

            // inversion occurs
            incr++;
        }
        else{
            sorted_array.push_back(A[l]); 
            l++;

            // l increased, add #r increments to total inversions
            inversions += incr;
        }
    }

    while( r <= right){
        // no more inversions in this subproblem
       sorted_array.push_back(A[r]);
       r++;
    }

    while ( l <= mid){
        // for each iteration, add #r increments to total inversions
        inversions += incr;
        sorted_array.push_back(A[l]);
        l++;
    }

    // update array
    for( int i = left; i <= right; i++){
        A[i] = sorted_array[i - left];
    }

    return inversions;
}


int inversions_count(vector<int> &A, int const left, int const right){
    int inversions = 0;

    if (left < right)
    {
        int mid = left + (right - left) /2;

        inversions += inversions_count(A, left, mid);
        inversions += inversions_count(A, mid + 1, right);
        inversions += merge_inversions(A, left, mid,  right);
    }   
    return inversions;
}

int main(){
    vector<vector<int>> test_case = {
        {4, 9, 7, 3, 1, 1, 5, 4},
        {16, 8, 4, 2, 1},
        {1, 1, 1, 1, 7, 1}
    };
}