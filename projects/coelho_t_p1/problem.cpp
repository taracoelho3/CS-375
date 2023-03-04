#include "problem.h"

problem::problem(){
    n = 0;
    w = 0;
}

problem::problem(int n, int w){
    this->n = n;
    this->w = w;
}

problem::problem(const problem &p){
    this->n = p.n;
    this->w = p.w;
    for(int i = 0; i < card_list.size(); i++){
        this->card_list[i] = p.card_list[i];
    }
}

int problem::get_weight(){
    return w;
}

void problem::add_card(card &new_card){
    card_list.push_back(new_card);
}

int problem::sum(){
    int result = 0;
    for(int i = 0; i < card_list.size(); i++){
        result = result + card_list[i].get_value();
    }
    return result;
}

void problem::print(){
    cout << "number of cards " << n << endl;
    cout << "max amount of money to spend " << w << endl;
    cout << card_list.size() << " size" << endl;
    for(int i = 0; i < card_list.size(); i++){
        card_list[i].print();
    }
}

problem& problem::operator=(const problem &p){
    this->n = p.n;
    this->w = p.w;
    for(int i = 0; i < card_list.size(); i++){
        this->card_list[i] = p.card_list[i];
    }
    return *this;
}