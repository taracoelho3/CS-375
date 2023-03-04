#include "item.h"

item::item(){
    weight = 0;
    profit = 0;
}

item::item(int weight, int profit){
    this->weight = weight;
    this->profit = profit;
}

void item::set_weight(int weight){
    this->weight = weight;
}

void item::set_profit(int profit){
    this->profit = profit;
}

int item::get_weight(){
    return weight;
}

int item::get_profit(){
    return profit;
}

item& item::operator=(const item &item){
    this->weight = item.weight;
    this->profit = item.profit;
    return *this;
}