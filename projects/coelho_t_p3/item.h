#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class item{
    public:
        item();
        item(int weight, int profit);
        void set_weight(int weight);
        void set_profit(int profit);
        int get_weight();
        int get_profit();
        item& operator=(const item &item);
    private:
        int weight;
        int profit;
};