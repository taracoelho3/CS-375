#include <string>
#include "LPHash.h"

using namespace std;

LPHash::LPHash(int size){
    this->slots = size;
    array = new int[slots];
    for(int i = 0; i < size; i++){
        array[i] = 0;
    }
}

std::string LPHash::insert(int k){
    std::string ret;
    int index = hashFunction(k);

    if(array[index] == 0){
        array[index] = k;
        return "Element " + std::to_string(k) + " inserted in position " + std::to_string(index) + ".\n";
    }
    else{
        while(array[index] != 0){
            index++;
            if(index == slots){
                index = 0;
            }
            if(array[index] == 0){
                array[index] = k;
                return "Original index full. Element " + std::to_string(k) + " inserted in position " + std::to_string(index) + ".\n";
                break;
            }
        }
    }
    return "Element failed to insert";
}

std::string LPHash::search(int k){
    int index = hashFunction(k);
  
    if(array[index] == k){
        return "Element " + std::to_string(k) + " found in " + std::to_string(index) + ". No probing necessary";
    }
    else{
        while(array[index] != 0){
            index++;

            if(index == slots){
                index = 0;
            }
            if(array[index] == 0){
                return "Element " + std::to_string(k) + "could not be found.";
            }
            if(array[index] == k){
                return "Element " + std::to_string(k) + " found in " + std::to_string(index) + ". Probing necessary";
            }
        }
    }
    return "Element " + std::to_string(k) + " could not be found.";
}
