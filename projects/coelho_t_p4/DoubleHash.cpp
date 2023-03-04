#include "DoubleHash.h"
DoubleHash::DoubleHash(int size, int c){
    array.resize(size);
    for (int i = 0; i < size; i ++){
        array[i] = -1; //NIL value
    }
    if (size == 10){
        prime = 7;
    }
    else if (size == 100){
        prime = 71;
    }
    else{
        prime = 701;
    }
    choose = c;
}
std::string DoubleHash::insert(int k){
    int h = -1; //hash value
    int i = 0;
    if (choose == 0){ //double hash, same hash function twice
        do {
            h = (k%array.size() + i*(k%array.size()))%array.size();
            if (array[h] == -1){
                array[h] = k;
                return "Element " + std::to_string(k) + " inserted in position " + std::to_string(h) + ".\n";
            }
            i++;
        } while (i != array.size());
    }
    else{ //double hash with primes
        do {
            h = (k%array.size() + i*(k%(array.size()/2)))%array.size();
            if (array[h] == -1){
                array[h] = k;
                return "Element " + std::to_string(k) + " inserted in position " + std::to_string(h) + ".\n";
            }
            i++;
        } while (i != array.size());
    }
    return "Element " + std::to_string(k) + " could not be inserted.\n"; 
}
std::string DoubleHash::search(int k){
    int h = -1;
    int i = 0;
    if (choose == 0){
        do {
            h = (k%array.size() + i*(k%array.size()))%array.size();
            if (array[h] == k){
                return "Element " + std::to_string(k) + " found in ";
            }
            i++;
        } while (array[h] != -1 && i != array.size());
    }
    else{
        do {
            h = (k%array.size() + i*(prime-(k%prime)))%array.size();
            if (array[h] == k){
                return "Element " + std::to_string(k) + " found in ";
            }
            i++;
        } while (array[h] != -1 && i != array.size());
    }
    return "Element " + std::to_string(k) + "could not be found. Took ";
}