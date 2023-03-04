#include "item.h"

class problem{
    public:
        problem();
        problem(int num_items, int capacity);
        void add_item(int weight, int profit);
        void set_num_items(int num_items);
        void set_capacity(int capacity);
        int get_num_items();
        int get_capacity();
        void print();
        void greedy_algorithm_1();
        void greedy_algorithm_2();
        void backtracking_algorithm();
    private:
        int num_items;
        int capacity;
        int curr_items;
        item *item_list;
};