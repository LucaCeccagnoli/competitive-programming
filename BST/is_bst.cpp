#include <iostream>
#include <queue>

struct Node{
    Node *parent, *left, *right;
    int key;
};

bool is_bst_inorder(Node &bst, int prev_key){
    // inorder visit prints nodes in ascending key order
    // if a key is smaller then the previous one, tree is not BST.

    is_bst_inorder( *bst.left, bst.key );

    if(bst.key > prev_key) return false;

    is_bst_inorder(*bst.right, bst.key);
    return true;
}