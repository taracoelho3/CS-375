class Node{
    int key = -1;
    Node* p;
    Node* l;
    Node* r;
    public:
        Node(int k, Node* par, Node* lef, Node* rig);
        ~Node(){
            delete p;
            delete l;
            delete r;
        }
        int get_key();
        Node* get_p();
        Node* get_l();
        Node* get_r();
        void set_key(int k);
        void set_p(Node* n);
        void set_l(Node* n);
        void set_r(Node* n);
};