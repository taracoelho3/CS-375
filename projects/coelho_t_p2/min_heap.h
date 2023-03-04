#include "contestant.h"
#include <sstream>
#include <fstream>

using namespace std;

class min_heap{
    public:
        min_heap();
        min_heap(int capacity, string out_file);
        int parent(int i);
        void build_heap();
        void min_heapify(int i);
        void min_heapify_up(int i);
        void update_handler();
        void find_contestant(int name);
        void insert_contestant(int name, int score);
        void earn_points(int id, int points);
        void show_contestants();
        void lose_points(int id, int points);
        void show_handles();
        void eliminate_weakest();
        void crown_winner();
        void show_location(int id);
        void print();
    private:
        int size;
        int capacity;
        contestant *arr;
        int *handler;
        string out_file;
        ofstream outFS;
};