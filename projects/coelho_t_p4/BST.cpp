#include "BST.h"
BST::BST(Node* root_node){
    root = root_node;
}
Node* BST::get_root(){
    return root;
}
void BST::set_root(Node* r){
    root = r;
}
std::string BST::search(Node* x, int k){
    if (x == nullptr){
        return "Element " + std::to_string(k) + " not found in tree. Took ";
    }
    else if (k == x->get_key()){
        return "Element " + std::to_string(k) + " found in ";;
    }
    if (k < x->get_key()){
        return search(x->get_l(),k);
    }
    else{
        return search(x->get_r(),k);
    }
}
std::string BST::insert(int k){
    /*if (root->get_key() != -1)
        std::cout << "root node is " << root->get_key() << std::endl;
    else
        std::cout << "root node has null value" << std::endl;*/
    //Node n(k,nullptr,nullptr,nullptr);
    //Node* z = &n;
    Node* y = nullptr;
    Node* x = root;
    while (x != nullptr){
        y = x;
        if (k < x->get_key()){
            x = x->get_l();
        }
        else{
            x = x->get_r();
        }
    }
    Node* z = new Node(k,nullptr,nullptr,nullptr);
    z->set_p(y);
    if (y == nullptr){
        root = z;
        return "Element " + std::to_string(z->get_key()) + " inserted as root.\n";
    }
    else if (z->get_key() < y->get_key()){
        y->set_l(z);
        return "Element " + std::to_string(z->get_key()) + " inserted as left child of " + std::to_string(y->get_key()) + ".\n";
    }
    else{
        y->set_r(z);
        return "Element " + std::to_string(z->get_key()) + " inserted as right child of " + std::to_string(y->get_key()) + ".\n";
    }
}