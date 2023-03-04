#include <string>
#include "LinkedList.h"

class LPHash{
    int *array;
    int slots;
    public:
        LPHash(int size);
        std::string insert(int k); 
        std::string search(int k);
        int hashFunction(int k) {
            return (k % slots);
        }
};