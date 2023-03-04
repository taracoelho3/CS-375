#include <string>
#include "LinkedList.h"

class ChainHash{
    LinkedList *table;
    int slots;
    public:
        ChainHash(int size);
        std::string insert(int k); 
        std::string search(int k);
        int hashFunction(int k) {
            return (k % slots);
        }
};