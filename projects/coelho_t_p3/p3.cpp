#include <sstream>
#include <fstream>
#include "problem.h"

using namespace std;

string input_file;
string output_file;
int algorithm;
problem problem;

void read_input(string input_file){
    ifstream inFS;
    int line_num = 0;

    inFS.open(input_file);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }

    int num_items;
    int capacity;
    string line;

    while(!(inFS.eof())){
        getline(inFS, line);

        stringstream ss(line);

        if(line_num == 0){
            ss >> num_items;
            ss >> capacity;

            problem.set_num_items(num_items);
            problem.set_capacity(capacity);

        }
        else{
            int weight;
            int profit;

            ss >> weight;
            ss >> profit;

            problem.add_item(weight, profit);
        }
        line_num++;
    }
    //problem.print();
}

int main(int argc, char** argv){

    if(argc != 4){
        cout << "Incorrect number of input arguments" << endl;
    }
    else{
        input_file = argv[1];
        output_file = argv[2];
        algorithm = atoi(argv[3]);
    }
    read_input(input_file);
    
    if(algorithm == 0){
        cout << "greedy algorithm 1" << endl;
        problem.greedy_algorithm_1();
    }
    if(algorithm == 1){
        cout << "greedy algorithm 2" << endl;
        problem.greedy_algorithm_2();
    }
    if(algorithm == 2){
        cout << "backtracking algorithm" << endl;
        problem.backtracking_algorithm();
    }
    return 0;
}