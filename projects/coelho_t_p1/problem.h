#include <stdio.h>
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class problem{
    public:
        problem();
        problem(int n, int w);
        problem(const problem &p);
        int get_weight();
        void add_card(card &new_card);
        int sum();
        void print();
        problem& operator=(const problem &p);
        vector<card> card_list;
    private:
        int n;
        int w;
};