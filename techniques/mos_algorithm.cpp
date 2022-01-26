#include <bits/stdc++.h>
using namespace std;

/*
    sample problem:
    Given  an array A[1,n] of distinct integers <= n, support a set of offline queries Q:
    query(i, j): return the number of distinct integers that occur at least 3 times in A[i,n]
*/

int block_size;
int at_least_3;
vector<int> arr;
vector<int> counters;   // integers are <=n, so every index can be mapped to a value easily.

struct Query{
    int l;
    int r;
};

bool compareQueries(Query q1, Query q2){
    // if on different blocks, sort by l
    if (q1.l/block_size != q2.l/block_size){
        return q1.l / block_size - q2.l / block_size;
    }

    // if on the same block, sort by r
    return q1.r < q2.r;
}

void add(int index){
     if (++counters[arr[index]] == 3){
         at_least_3++;
     }
}

void remove(int index){
    if(--counters[arr[index]] == 2){
        at_least_3--;
    }
}

void queryResults(vector<Query> queries){
    block_size = sqrt(arr.size());
    counters = vector<int>(arr.size());

    sort(queries.begin(), queries.end(), compareQueries);

    int curr_left = 0, curr_right = 0, next_left, next_right;

    for(int i = 0; i < queries.size(); i++){
        next_left = queries[i].l;
        next_right = queries[i].r;

        while(next_left < curr_left){
            remove(curr_left);
            curr_left++;
        }
        while(next_left > curr_left){
            add(curr_left);
            curr_left --;
        }
        while(next_right < curr_right){
            remove(curr_right);
            curr_right--;
        }
        while(next_right > curr_right){
            add(curr_right);
            curr_left++;
        }

        cout<< "numbers that occur at least 3 times in (" 
            << next_left << ", " << next_right << ") = "
            << at_least_3 << endl;
    }
}

int main(){
    arr = vector<int>{3, 1, 6, 4, 6, 6, 1, 1};
    counters = vector<int>(arr.size());
    vector<Query> queries{{0,3}, {2, 5}, {1, 7}};
    queryResults(queries);
}