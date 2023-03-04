#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class card{
    public:
        card();
        card(string name, int value);
        card(const card &c);
        string get_name();
        int get_value();
        void set_name(string name);
        void set_value(int value);
        void print();
    private:
        string name;
        int value;
};