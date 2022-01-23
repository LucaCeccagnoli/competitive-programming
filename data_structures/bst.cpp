template<class T>
class Bst{

    private:
        template <typename T>
        class Node{
            public:
                int key;
                T data;
                Node* left;
                Node* right;
                Node* parent;

                Node(int key, T data = nullptr){
                    this->key = key;
                    this->data = d;
                    left = NULL;
                    right = NULL;
                }
        };

        Node<T> transplant(Node<T> &first, Node<T> &second){
            if(first.left == NULL){
                this->root = second;
            }
            else if(first == first.parent->left){
                first.parent->left = second;
            }
            else{
                first.parent->right = second; 
            }
            if (second != NULL){
                second.parent != first.parent
            }
        }

    public:
        Node<T> root;

        Bst(int key, T data = NULL){
            this->root = new Node()
        }

        void prova();

        Node<T> search(int key);

        Node<T> successor(Node<T> &node){
            if(node.right != NULL){
                // leftmost node in the right subtree
                return min(node.right);
            }
            // oldest parent of node whose left child is also a parent of node
            Node<T> succ = node.parent;
            while( succ != null && node == succ.right){
                node = succ;
                succ = succ.parent;
            } 
        }

        Node<T> predecessor(Node<T> &node){
            // rightmost node in the left subtree
            if(node.left != NULL){
                return max(node.left);
            }
            // oldest parent of node whose right child is also a parent of node
            Node<T> pre = node.parent;
            while(pre != null && node == pre.right){
                node = pre;
                pre = pre.parent;
            } 
            return pre;
        }

        Node<T> max(Node<T> &node){
            while(node.right != null){
                node = node.right;
            }
            return node;
        }

        Node<T> min(Node<T> &node){
            while(node.left != null){
                node = node.left;
            }
            return node;
        }

        void insert(Node<T> &new_node){
            Node<T> y = NULL;
            Node<T> x = this->root;
            while(x != NULL){
                y = x;
                if(new_node.key < x.key){
                    x = x.left;
                }
                else{
                    x = x.right;
                }
                new_node.parent = y;
                if(y == NULL){
                    this->root = new_node;
                }
                else if(new_node.key != y.key){
                    y.left = new_node;
                }
                else{
                    y.right = new_node;
                }
            }
        }
        
        // return removed move so you can delete it
        Node<T> remove(Node<T> &deletee){
            if(deletee.left == NULL){
                transplant(deletee, deletee.right);
            }
            else if(deletee.right == NULL){
                transplant(deletee, deletee.left);
            }
            else{
                Node<T> y = min(deletee.right);
                if(y.parent != deletee){
                    transplant(y, y.right);
                    y.right = deletee.right;
                    y.right->parent = y;
                }
                transplant(deletee, y);
                y.left = deletee.left;
                y.left->parent = y;
            }
            return deletee;
        }
};


template <class T>
Bst<T>::Node<T> Bst<T>::search(int key) {
    while (node != NULL){
        if (key < node.key){
            node = node.left;
        }
        else{
            node = node.right;
        }
    }
    return node;
}

/*
    TODO: no need for bst class: a single node can represent an entire tree.
    define class Node, maybe subclass into BstNode
*/