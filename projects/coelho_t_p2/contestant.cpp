#include "contestant.h"

using namespace std;

contestant::contestant(){
    id = 0;
    points = 0;
}

contestant::contestant(int id, int points){
    this->id = id;
    this->points = points;
}

int contestant::get_name(){
    return id;
}

int contestant::get_points(){
    return points;
}

void contestant::set_name(int id){
    this->id = id;
}

void contestant::add_points(int more_points){
    this->points += more_points;
}

void contestant::lose_points(int more_points){
    this->points -= more_points;
}

void contestant::print(){
    cout << "ID: " << id << " Points: " << points << endl;
}

contestant& contestant::operator=(const contestant &c){
    this->id = c.id;
    this->points = c.points;
    return *this;
}

bool contestant::operator>(const contestant &c)const{
    return points > c.points;
}

bool contestant::operator<(const contestant &c)const{
    return points < c.points;
}