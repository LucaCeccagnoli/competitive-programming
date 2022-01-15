#include <iostream>
#include <algorithm>

struct Node{
    int value;
    struct Node *left, *right;

   Node(int value) : value(value){
       left = NULL;
       right = NULL;
   }
};


int max_path_sum_util(Node *node, int &best_subtree_weight){
    int left_subtree_max = 0, right_subtree_max = 0;
    std::cout << "preorder: " << node->value << std::endl;         // nullptr causes segmentation fault here

    // postorder visit
    left_subtree_max = 
        node->left ?
        max_path_sum_util(node->left, best_subtree_weight) :
        0;


    right_subtree_max = 
        node->right ? 
        max_path_sum_util(node->right, best_subtree_weight):
        0;

    if(node-> left && node->right){
        // maximum path sum for this subtree.
        best_subtree_weight = std::max(best_subtree_weight, left_subtree_max + right_subtree_max + node->value);

        // value returned by this node for heigher subtrees.
        return std::max(left_subtree_max, right_subtree_max) + node->value;
    }
    else{
        return (!node->left) ? 
            right_subtree_max + node->value : 
            left_subtree_max + node->value;
    }

    return std::max(left_subtree_max, right_subtree_max) + node->value;
}

int max_path_sum(Node *node){
    int best_subtree_weight = INT8_MIN;
    int result = max_path_sum_util(node, best_subtree_weight);

    return best_subtree_weight == INT8_MIN ? result : best_subtree_weight;
}

int main(){
    Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right = new Node(0);
    root->right->right->right->left = new Node(4);
    root->right->right->right->right = new Node(-1);
    root->right->right->right->right->left = new Node(10);

    std::cout << "max path sum is: " << max_path_sum(root) << " , correct answer is 27" << std::endl;
}