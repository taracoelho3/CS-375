#include "problem.h"

using namespace std;

problem::problem(){
    num_items = 0;
    capacity = 0;
    curr_items = 0;
    item_list = new item[10000];
}

problem::problem(int num_items, int capacity){
    this->num_items = num_items;
    this->capacity = capacity;
    curr_items = 0;
    item_list = new item[capacity];
}

void problem::add_item(int weight, int profit){
    item item(weight, profit);

    item_list[curr_items] = item;
    curr_items++;
}

void problem::set_num_items(int num_items){
    this->num_items = num_items;
}

void problem::set_capacity(int capacity){
    this->capacity = capacity;
}

int problem::get_num_items(){
    return num_items;
}

int problem::get_capacity(){
    return capacity;
}

void problem::print(){
    cout << "num_items: " << num_items << endl;
    cout << "capacity: " << capacity << endl;

    for(int i = 0; i < curr_items; i++){
        cout << "weight: " << item_list[i].get_weight() << "  profit: " << item_list[i].get_profit() << endl;
    }
}

void greedy_algorithm_1(){

}

void greedy_algorithm_2(){
    
}

void backtracking_algorithm(){
    
}