#include "card.h"

using namespace std;

card::card(){
    name = "";
    value = 0;
}

card::card(string name, int value){
    this->name = name;
    this->value = value;
}

card::card(const card &c){
    this->name = c.name;
    this->value = c.value;
}

string card::get_name(){
    return name;
}

int card::get_value(){
    return value;
}

void card::set_name(string name){
    this->name = name;
}

void card::set_value(int value){
    this->value = value;
}

void card::print(){
    cout << name << " " << value << endl;
}