#include "project1.h"
#include <ctime>
#include <math.h>

using namespace std;

struct result{
    int profit;
    vector<card> max_set;
};

void add_card(problem &problem, card &card){
    problem.add_card(card);
}

void read_market_price(string market_price){
    ifstream inFS;
    ofstream outFS;
    //string currName;
    int lineNum = 0;
    int num_cards = 0;
    
    inFS.open(market_price);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }
  
    while(!inFS.eof()){
        int value;
        string identifier;
        string line;

        getline(inFS, line);

        stringstream ss(line);

        if(lineNum == 0){
            ss >> num_cards;
        }

        ss >> identifier;
        ss >> value;

        card new_card(identifier, value);
        card_list.push_back(new_card);

        lineNum++;
    }
}

void read_price_list(string price_list){
    ifstream inFS;
    ofstream outFS;
    int lineNum = 0;
    int problem_num = 0;
    
    inFS.open(price_list);

    if(!inFS.is_open()){
        cout << "Could not open file" << endl;
    }
  
    while(!inFS.eof()){
        string line;
        string name;
        int val;
        int n;
        int w;

        getline(inFS, line);

        stringstream st(line);

        if(st >> n){
            st >> w;
            problem *new_problem = new problem(n, w);
            problem_list.push_back(new_problem);

            for(int i = 0; i < n; i++){   
                getline(inFS, line);
                stringstream st(line);

                st >> name;
                st >> val;
              
                card new_card(name, val);
                new_problem->add_card(new_card);
            }
        }
        lineNum++;
    }
}

int sum(vector<card> card_list){
    int result = 0;
    for(int i = 0; i < card_list.size(); i++){
        result = result + card_list[i].get_value();
    }
    return result;
}

int get_bit(int val, int pos){
    int bit = val & (int)pow(2, pos);
    return (bit > 0 ? 1 : 0);
}

int compute_market_price(string name){
    int market_value = 0;
    for(int i = 0; i < card_list.size(); i++){
        if(card_list[i].get_name() == name){
            market_value = card_list[i].get_value();
        }
    }
    return market_value;
}

int compute_profit(problem *problem){
    int profit = 0;
    int market_price = 0;
    int actual_price = 0;
    string name;

    for(int i = 0; i < problem->card_list.size(); i++){
        actual_price = problem->card_list[i].get_value();
        name = problem->card_list[i].get_name();

        int market_price = compute_market_price(name);
        profit += market_price - actual_price;
    } 
    return profit;
} 

int compute_profit(vector<card> card_list){
    int profit = 0;
    int market_price = 0;
    int actual_price = 0;
    string name;

    for(int i = 0; i < card_list.size(); i++){
        actual_price = card_list[i].get_value();
        name = card_list[i].get_name();

        int market_price = compute_market_price(name);
        profit += market_price - actual_price;
    } 
    return profit;
} 

result max_profit(vector<card> new_list, int w){
    std::clock_t start;
    start = std::clock();

    result result;
    int max_profit = 0;
    int curr_set_num = 0;
    int n = new_list.size();
    int num_sets = (int)pow(2, n);
    vector<card> max_set;

    outFS << new_list.size() << endl;

    if(sum(new_list) <= w){
        result.profit = compute_profit(new_list);
        result.max_set = new_list;
    }
    else{
        for(int i = 0; i < num_sets; i++){
            vector<card> current_set;
            for(int bit = 0; bit < new_list.size(); bit++){
                if(get_bit(i, bit) == 1){
                    current_set.push_back(new_list[bit]);
                }
            }

            if(sum(current_set) <= w){
                if(compute_profit(current_set) > max_profit){
                    max_profit = compute_profit(current_set);
                    max_set = current_set;
                }     
            }
            curr_set_num++;
        } 
        result.profit = max_profit;
        result.max_set = max_set;
    }
 
    double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    outFS << result.profit << endl;
    outFS << result.max_set.size() << endl;
    outFS << duration << endl;

    for(int i = 0; i < result.max_set.size(); i++){
        outFS << result.max_set[i].get_name() << endl;
    }

    outFS << endl;
    return result;
}  

int main(int argc, char** argv){
    if(argc != 5){
        cout << "Incorrect number of input arguments" << endl;
    }
    else{
        for(int i = 0; i < 5; i++){
            string flag = argv[i];
            if(flag == "-p"){
                price_list_file = argv[i + 1];
            }
            if(flag == "-m"){
                market_price_file = argv[i + 1];
            }
        }
    }

    read_market_price(market_price_file);
    read_price_list(price_list_file);

    outFS.open("output.txt");

    for(int i = 0; i < problem_list.size(); i++){
       result result = max_profit(problem_list[i]->card_list, problem_list[i]->get_weight());
    }
    return 0;
}