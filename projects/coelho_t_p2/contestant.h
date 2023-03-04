#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class contestant{
    public:
        contestant();
        contestant(int id, int points);
        int get_name();
        int get_points();
        void set_name(int id);
        void add_points(int more_points);
        void lose_points(int more_points);
        void print();
        contestant& operator=(const contestant &c);
        bool operator>(const contestant &c) const;
        bool operator<(const contestant &c) const;
    private:
        int id;
        int points;
};