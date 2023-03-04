#include "min_heap.h"
#include <sstream>
#include <fstream>

using namespace std;

string input_file;
string output_file;

string options[100] = {"insertContestant", "showLocation", "showContestant", "findContestant", "eliminateWeakest", "losePoints", "earnPoints", "showContestants", "showHandles", "crownWinner"};

int extract_int(string input){

    size_t i = 0;
    for( ; i < input.length(); i++ ){
        if(isdigit(input[i])){
            break;
        }
    }

    input = input.substr(i, input.length() - i );

    int in = atoi(input.c_str());
    return in;
}

void read_input(string file_name){
    ifstream inFS;
    int line_num = 0;

    inFS.open(file_name);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }

        string option;
        string line;
        string id;
        string score;
        int capacity;

        getline(inFS, line);

        stringstream ss(line);

        ss >> capacity;

        min_heap heap(capacity, output_file);

        int num = 0;
        while(!(inFS.eof())){
            getline(inFS, line);

            stringstream ss(line);

            ss >> option;

            bool flag = false;
            for(int i = 0; i < 10; i++){
                if(option == options[i]){
                    flag = true;
                }
            } 
            if(flag == false){
                cout << "not a valid option  "<< option << endl;
            }
            else{
               if(option == "findContestant"){
                   ss >> id;
                   int new_id = extract_int(id);
                   heap.find_contestant(new_id);
                }
               else if(option == "insertContestant"){
                   ss >> id;
                   ss >> score;
                   int new_id = extract_int(id);
                   int new_score = extract_int(score);
                   heap.insert_contestant(new_id, new_score);
               }
               else if(option == "earnPoints"){
                   ss >> id;
                   ss >> score;
                   int new_id = extract_int(id);
                   int new_score = extract_int(score);
                   heap.earn_points(new_id, new_score);
               }
               else if(option == "showContestants"){
                   heap.show_contestants();
               }
               else if(option == "losePoints"){
                   ss >> id;
                   ss >> score;
                   int new_id = extract_int(id);
                   int new_score = extract_int(score);
                   heap.lose_points(new_id, new_score);
               }
               else if(option == "showHandles"){
                   heap.show_handles();
               }
               else if(option == "eliminateWeakest"){
                   heap.eliminate_weakest();
               }
               else if(option == "crownWinner"){
                    heap.crown_winner();
               }
               else if(option == "showLocation"){
                    ss >> id;
                    int new_id = extract_int(id);
                    heap.show_location(new_id);
               }
            }
        num++;
    }
}

int main(int argc, char** argv){

    if(argc != 3){
        cout << "Incorrect number of input arguments" << endl;
    }
    else{
        input_file = argv[1];
        output_file = argv[2];
    }
    
    read_input(input_file);
    return 0;
}