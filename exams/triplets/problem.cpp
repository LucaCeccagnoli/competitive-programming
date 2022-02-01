#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2
#define PARENT(i) (i-1)/2

template<typename T>
struct SegmentTree{
    public:
        SegmentTree(vector<T> arr){
            // next power of 2 for the total number of nodes
            arr_size = arr.size();
            tree_size = 2 * arr_size - 1; 
            tree = vector<T>(size, 0);

            for(int i = 0; i < arr_size; i++){
                tree[arr_size+i] = arr[i]
            }
        }

        void buildPref(){
            for(int = arr_size - 1; i > 0; --i){
                tree[i] = tree[]
            }
        }

        void buildSuf(){

        };

        T getRoot();
    private:
        size_t arr_size, tree_size;
        vector<T> tree;
};
