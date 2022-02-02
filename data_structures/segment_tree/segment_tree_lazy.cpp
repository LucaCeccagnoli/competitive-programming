#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>

#define LEFT(i) i*2 + 1
#define RIGHT(i) i*2 + 2
#define PARENT(i) i/2
#define HALF(i, j) i + (j-i)/2 

struct Tree{
    public: 
    std::vector<int> tree;
    const int arr_size;

        Tree(std::vector<int> &arr): arr_size(arr.size()){
            int st_size = arr_size * 2 -1;

            tree = std::vector<int>(st_size);
            updates = std::vector<int>(st_size);

            for(int i = 0; i < arr_size; i++){
                tree[i + arr_size - 1] = arr[i];
            }
            for(int i = arr_size-2; i >= 0; i--){
                tree[i] = std::min( tree[LEFT(i)], tree[RIGHT(i)]);
            }
        }

        void update(int start, int end, int value);
        int queryMin(int start, int end);

    private:
        std::vector<int> updates;   // segment tree for updates
        void updateUtil(int start, int end, int value, int left, int right, int index);
        int queryMinUtil(int start, int end, int left, int right, int index);
        void set_min(int index);

        void addUpdate(int index, int value){
            updates[index] += value;
        }

        void applyUpdate(int index){
            int val = updates[index];

            //if node has children, propagate the update
            if(RIGHT(index) < updates.size())
                updates[RIGHT(index)] += val;

            if(LEFT(index) < updates.size())
                updates[LEFT(index)] += val;
            
            updates[index] = 0;
            tree[index] += val;
        }
};

void Tree::update(int start, int end, int value){
    updateUtil(start, end, value, 0, arr_size-1, 0);  // root
}

int Tree::queryMin(int start, int end){
    return queryMinUtil(start, end, 0, arr_size-1, 0);
}

void Tree::set_min(int index){
    if(RIGHT(index) < tree.size() && LEFT(index) < tree.size()){
        tree[index] = std::min(tree[LEFT(index)], tree[RIGHT(index)]);
    }
}

void Tree::updateUtil(int start, int end, int value, int left, int right, int index){
    int left_child_val, right_child_val;

    if(updates[index] != 0){
        applyUpdate(index);
    }
    // total overlap
    if(start <= left && end >= right){
        // directly increase the value and propagate to children
        addUpdate(index, value);
        applyUpdate(index);
    }
    // no overlap
    else if(start > right || end < left){
        // do nothing
    }
    // partial overlap
    else{
        int a = right/2 + 1;
        updateUtil(start, end, value, left, HALF(left, right), LEFT(index));
        updateUtil(start, end, value, HALF(left, right) + 1, right, RIGHT(index));

        // update current node
        set_min(index);
    }
}

int Tree::queryMinUtil(int start, int end, int left, int right, int index){
    // query needs to check for pending updates!
    if(updates[index] != 0){
        applyUpdate(index);
    }

    if(start <= left && end >= right){
        // segment fully overlaps
        return tree[index];
    }
    else if(start > right || end < left){
        // segment does not overlap
        return INT_MAX;
    }
    else{
        //segments partially overlap
        return std::min(
            queryMinUtil(start, end, left, HALF(left, right), LEFT(index)),
            queryMinUtil(start, end, HALF(left, right) + 1, right, RIGHT(index))
        );;
    }
    
}

int input(){
    int n, m, val;          // to save inputs
    std::string str;          

    std::vector<int> arr;   // array for the problem
    std::cout << "input array size" << std::endl;
    std::cin >> n;

    std::cout << "input array elements" << std::endl;
    for(int i = 0; i < n; i++){
        std::cin >> val;
        arr.push_back(val);
    }

    Tree t(arr);    // initialize segment tree

    std::cout << "input number of queries" << std::endl;
    std::cin >> m;
    std::cout << "input queries " << std::endl;

    std::cin.ignore();
    for(int i = 0; i < m; i++){
        std::vector<int> params;

        // take parameters separated by space on a single line
        std::getline(std::cin, str);
        std::stringstream ss(str);
        while(ss >> val){
            params.push_back(val);
        }

        if(params.size() == 3){
            t.update(params[0], params[1], params[3]);
            std::cout << "updated: " << std::endl;
        }
        else if(params.size() == 2){
            std::cout << "rmq: " << t.queryMin(params[0], params[1]) << std::endl;
        }
        else{
            std::cout << "wrong parameters" << std::endl;
            i--;
            continue;
        }
    }
    return 0;
}