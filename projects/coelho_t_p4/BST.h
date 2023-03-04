#include "Node.h"
#include <string>
#include <iostream>
class BST{
    Node* root = nullptr;
    public:
        BST(Node* root_node);
        BST(){};
        Node* get_root();
        void set_root(Node* r);
        std::string search(Node* x, int k);
        std::string insert(int k);
};