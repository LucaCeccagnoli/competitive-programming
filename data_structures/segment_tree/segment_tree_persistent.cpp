#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define MID(l,r) l + (r - l) / 2 

struct Node{
    int value;
    Node *left, *right;

    Node(){};
    Node(Node *left, Node *right, int value){
        left = left;
        right = right;
        value = value;
    }

};

template<typename T>
struct PTree{
    public:
        vector<Node*> versions;

        void PTree(vector<T>const &arr){
            arr_size = arr.size();
            Node* root = new Node(NULL,NULL,0);
            build(arr, root, 0, arr_size -1);
        }

        void upgrade(int index, T value){
            Node* new_root = new Node(NULL, NULL, 0);

            // insert new node in the version array
            versions.push_back(new_root);
            upgradeUtil(*versions.end() - 2, new_root, 0, arr_size-1, index, value);
        }

        T query(int i, int j, int timestamp){
            Node* version = versions[timestamp];
            return queryUtil(version, i, j, 0, arr_size-1)
        }

    private:
        int arr_size;

        void build(vector<T>const &arr, node *node, int left, int right){
            if(left == right){
                node->value = arr[node];
            }
            node->left = new Node(NULL,NULL,0);
            node->right = new Node(NULL, NULL; 0);

            build(arr, node->left, left, MID(left, right));
            build(arr, node->right, MID(left, right) + 1, right);

            node->value = node->left->value + node->right->value;
        };

        // update a node, inserting new values in a new version
        void upgradeUtil(Node* prev, Node*cur, int left, int right, int index, T value){
            // index is not on subtree
            if(index > right || index < left || left > right){
                return;
            }

            // index is on subtree
            if(left == right){
                // set value in the new node
                cur->value = value;
                return;
            }

            // if element to update is on the left
            if(index < MID(left, right)){
                // right child takes value from previous version
                cur->right = prev->right;
                cur->left = new Node(NULL, NULL, 0)
                upgradeUtil(prev->left, cur->left, left, MID(left, right), index, value);
            }

            // if element to update is on the right
            else{
                // left child takes value from previous version
                cur-> left = prev->left;
                upgradeUtil(prev->right, cur->right, MID(left, right) + 1, right, index, value);
            }

            // update node value
            cur->value = cur->left->value + cur->right->value
        }

        T queryUtil(Node *node, int i, int j, int left, int right){
            //full overlap
            if(i < left && j > right){
                return node->value;
            }
            else if(i < left && j < left || i > right && j > right){
                return 0;
            }
            else{
                return queryUtil(node->left, i, j, left, MID(left, right)) +
                    queryUtil(node->right, i, j, MID(left,right) +1);
            }
        }
};