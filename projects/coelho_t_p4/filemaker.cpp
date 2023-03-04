#include <string>
#include <fstream>
int main(int argc, char** argv){
    std::string arg1 = argv[1];
    std::string arg2 = argv[2];
    std::ofstream out_file(arg1);
    int size = std::stoi(arg2);
    std::string output = "";
    for (int i = 0; i < size; i ++){
        output += "insert " + std::to_string(i) + "\n";
    }
    out_file << output;
    out_file.close();
    return 0;
}