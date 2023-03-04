#include <string>
#include "ChainHash.h"

ChainHash::ChainHash(int size){
    this->slots = size;
    table = new LinkedList[slots];
}

std::string ChainHash::insert(int k){
    std::string ret;
    int index = hashFunction(k);
    table[index].push_back(k);

    if(table[index].head->next == NULL){
        return "Element " + std::to_string(k) + " inserted in position " + std::to_string(index) + ".\n";
    } else {
        return "Element " + std::to_string(k) + " chained to list in position " + std::to_string(index) + ".\n";
    }
}

std::string ChainHash::search(int k){
    int index = hashFunction(k);
    Node *temp = table[index].head;

    while(temp != NULL){
        if(temp->data == k){
            return "Element " + std::to_string(k) + " found in ";
        }
        else{ temp = temp->next; }
    }
    return "Element " + std::to_string(k) + "could not be found. Took ";
}