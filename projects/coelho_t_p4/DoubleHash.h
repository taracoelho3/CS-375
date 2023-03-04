#include <vector>
#include <string>
class DoubleHash{
    std::vector<int> array;
    int prime;
    int choose;
    public:
        DoubleHash(int size, int c);
        std::string insert(int k); 
        std::string search(int k);
};