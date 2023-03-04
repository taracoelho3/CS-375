#include "Node.h"
Node::Node(int k, Node* par, Node* lef, Node* rig){
    key = k;
    p = par;
    l = lef;
    r = rig;
}
int Node::get_key(){
    return key;
}
Node* Node::get_p(){
    return p;
}
Node* Node::get_l(){
    return l;
}
Node* Node::get_r(){
    return r;
}
void Node::set_key(int k){
    key = k;
}
void Node::set_p(Node* n){
    p = n;
}
void Node::set_l(Node* n){
    l = n;
}
void Node::set_r(Node* n){
    r = n;
}