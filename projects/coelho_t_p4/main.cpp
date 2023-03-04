#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <chrono>
#include <tuple>
#include "BST.h"
#include "DoubleHash.h"
#include "LPHash.h"
#include "ChainHash.h"

std::string do_linear(std::string file_name){
    std::string output = ""; //output string
    std::vector<int> array;
    std::string line;
    std::ifstream in_file(file_name);
    while (getline(in_file,line)){
        std::stringstream ss(line); //stringstream of line being read
        std::istream_iterator<std::string> init(ss); //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the first element
        std::istream_iterator<std::string> term; //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the last element
        std::vector<std::string> parts(init, term);
        std::string inst = parts[0];
        int element = std::stoi(parts[1]); 
        if (inst == "insert"){
            array.push_back(element);
            output += "Element " + std::to_string(element) + " inserted.\n";
        }
        else if (inst == "search"){
            auto start = std::chrono::high_resolution_clock::now(); //start timer
            bool found = false;
            for (int i : array){
                if (i == element){
                    auto stop = std::chrono::high_resolution_clock::now(); //stop timer
                    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
                    found = true;
                    output += "Element " + std::to_string(element) + " found in " + std::to_string(duration.count()/1000.0) + " milliseconds.\n";
                }
            }
            if (!found){
                auto stop = std::chrono::high_resolution_clock::now(); //stop timer
                auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
                output += "Element " + std::to_string(element) + " not found. Took " + std::to_string(duration.count()/1000.0) + " milliseconds.\n";
            }
        }
    }
    
    return output;
}

std::string do_binary(std::string file_name,int balance){
    std::string output = "";
    std::ifstream in_file(file_name);
    BST tree;
    std::string line;
    while (getline(in_file,line)){
        std::stringstream ss(line); //stringstream of line being read
        std::istream_iterator<std::string> init(ss); //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the first element
        std::istream_iterator<std::string> term; //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the last element
        std::vector<std::string> parts(init, term);
        std::string inst = parts[0];
        int element = std::stoi(parts[1]); 
        if (inst == "insert"){
            output += tree.insert(element);
        }
        else if (inst == "search"){
            if (balance == 2){
                tree.set_root(tree.balance_tree(tree.get_root()));
                //tree.preOrder(tree.get_root());
            }
            auto start = std::chrono::high_resolution_clock::now(); //start timer
            output += tree.search(tree.get_root(), element);
            auto stop = std::chrono::high_resolution_clock::now(); //stop timer
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
            output += std::to_string(duration.count()/1000.0) + " milliseconds.\n";
        }
    }
    return output;
}

std::string do_double_hash(std::string file_name, int prob_type, int prob_size){
    std::string output = "";
    std::ifstream in_file(file_name);
    int choose = prob_type-3;
    DoubleHash hash_table(prob_size,choose);
    std::string line;
    while (getline(in_file,line)){
        std::stringstream ss(line); //stringstream of line being read
        std::istream_iterator<std::string> init(ss); //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the first element
        std::istream_iterator<std::string> term; //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the last element
        std::vector<std::string> parts(init, term);
        std::string inst = parts[0];
        int element = std::stoi(parts[1]); 
        if (inst == "insert"){
            output += hash_table.insert(element);
        }
        else if (inst == "search"){
            auto start = std::chrono::high_resolution_clock::now(); //start timer
            output += hash_table.search(element);
            auto stop = std::chrono::high_resolution_clock::now(); //stop timer
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
            output += std::to_string(duration.count()/1000.0) + " milliseconds.\n";
        }
    }
    return output;
}

std::string do_linprob_hash(std::string file_name, int prob_size){
    std::string output = "";
    std::ifstream in_file(file_name);
    LPHash hash_table(prob_size);
    std::string line;
    while (getline(in_file,line)){
        std::stringstream ss(line); //stringstream of line being read
        std::istream_iterator<std::string> init(ss); //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the first element
        std::istream_iterator<std::string> term; //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the last element
        std::vector<std::string> parts(init, term);
        std::string inst = parts[0];
        int element = std::stoi(parts[1]); 
        if (inst == "insert"){
            output += hash_table.insert(element);
        }
        else if (inst == "search"){
            auto start = std::chrono::high_resolution_clock::now(); //start timer
            output += hash_table.search(element);
            auto stop = std::chrono::high_resolution_clock::now(); //stop timer
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
            output += std::to_string(duration.count()/1000.0) + " milliseconds.\n";
        }
    }
    return output;
}

std::string do_chain_hash(std::string file_name, int prob_size){
    std::string output = "";
    std::ifstream in_file(file_name);
    ChainHash hash_table(prob_size);
    std::string line;
    while (getline(in_file,line)){
        std::stringstream ss(line); //stringstream of line being read
        std::istream_iterator<std::string> init(ss); //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the first element
        std::istream_iterator<std::string> term; //istream_iterator for breaking ss into strings based on white space as a delimiter, used to denote the last element
        std::vector<std::string> parts(init, term);
        std::string inst = parts[0];
        int element = std::stoi(parts[1]); 
        if (inst == "insert"){
            output += hash_table.insert(element);
        }
        else if (inst == "search"){
            auto start = std::chrono::high_resolution_clock::now(); //start timer
            output += hash_table.search(element);
            auto stop = std::chrono::high_resolution_clock::now(); //stop timer
            auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); //get runtime
            output += std::to_string(duration.count()/1000.0) + " milliseconds.\n";
        }
    }
    return output;
}
//main function which parses input file, makes a call to do_problem which calls the appropriate function and returns its output, and writes that output to the output file
int main(int argc, char** argv){
    //if incorrect number of arguments
    if (argc != 4 && argc != 5){
        std::cout << "Improper number of arguments. Exiting." << std::endl;
        exit(1);
    }

    //collect command line arguments
    std::string arg1 = argv[1];
    std::string arg2 = argv[2];
    std::string arg3 = argv[3];
    int prob_size = 0;
    if (argc == 5){
        prob_size = std::stoi(argv[4]); 
    }

    std::string output = "";

    std::ofstream out_file(arg2); //output file
    int prob_type = std::stoi(arg3); //which function to execute

    if (prob_type == 0){
        output += do_linear(arg1);
    }
    else if (prob_type == 1 || prob_type == 2){
        output += do_binary(arg1,prob_type);
    }
    else if (prob_type == 3 || prob_type == 4){ //prob_type == 3,4,
        output += do_double_hash(arg1,prob_type,prob_size);
    }
    else if (prob_type == 5){
        output += do_linprob_hash(arg1,prob_size);
    }
    else{ //prob_type == 6
        output += do_chain_hash(arg1,prob_size);
    }

    out_file << output; //write output to output file
    out_file.close();
    return 0;
}