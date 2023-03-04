struct Node {
    int data;
    Node* next;
};

class LinkedList {
  public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void push_back(int newElement) {
        Node* newNode = new Node();
        newNode->data = newElement;
        newNode->next = NULL; 
        if(head == NULL) {
            head = newNode;
        } else {
        Node* temp = head;
        while(temp->next != NULL){ temp = temp->next; }
        temp->next = newNode;
      }    
    }
};