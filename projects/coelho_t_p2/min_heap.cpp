#include "min_heap.h"

using namespace std;

min_heap::min_heap(){
    size = 1;
    capacity = 1;
    arr = new contestant[1];
    handler = new int[capacity + 1];
    for(int i = 0; i < capacity + 1; i++){
        handler[i] = -1;
    }
}

min_heap::min_heap(int capacity, string out_file){
    this->capacity = capacity + 1;
    this->size = 1;
    this->out_file = out_file;
    arr = new contestant[capacity + 1];
    handler = new int[capacity + 1];
    for(int i = 0; i < capacity + 1; i++){
        handler[i] = -1;
    }
    
    outFS.open(out_file);

    if(!outFS.is_open()){
        cout << "Could not open file" << endl;
    }
}

int min_heap::parent(int i){
    return(i) / 2;
}

void min_heap::build_heap() {
    for (int i = (size/2) + 1; i > 0; i--) {
        min_heapify(i);
    }
    update_handler();
}

void min_heap::min_heapify(int i) {
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    if (l < size && arr[l] < arr[i]) {
        smallest = l;
    }
    if (r < size && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        contestant temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        min_heapify(smallest);
    }
}

void min_heap::min_heapify_up(int i){
    if(i && arr[parent(i)] > arr[i]){
        contestant temp = arr[i];
        arr[i] = arr[parent(i)];
        arr[parent(i)] = temp;
        min_heapify_up(parent(i));
    }
}

void min_heap::update_handler(){
    for(int i = 1; i < capacity; i++){
        int curr_id = arr[i].get_name();
        if(curr_id != 0){
            handler[curr_id] = i;
        }
    } 
  
}

void min_heap::find_contestant(int name){

    outFS << "findContestant <" << name << ">" << endl;

    if(handler[name] == -1 || name > capacity){
        outFS << "Contestant <" << name << "> is not in the extended heap." << endl;
    }
    else{
        outFS << "Contestant <" << name << "> is in the extended heap with score <" << arr[handler[name]].get_points() << ">." << endl;
    }
    return;
}

void min_heap::insert_contestant(int name, int score){
    contestant curr(name, score);

    outFS << "insertContestant " << "<" << name << ">" << " <" << score << ">." << endl;
 
    bool flag = false;
    for(int i = 1; i < capacity; i++){
        if(name == arr[i].get_name()){
            flag = true;
            outFS << "Contestant <" << name << "> is already in the extended heap: could not insert." << endl;
            return;
        } 
    }
    if(flag == false && capacity > 0){
        if(size + 1 > capacity){
            outFS << "Contestant <" << name << "> could not be inserted because the extended heap is full." << endl;
        }
        else{
            arr[size] = curr;
            size++;
            build_heap();
            outFS << "Contestant <" << name << "> inserted with initial score <" << score << ">." << endl;
        }
    }
    return;
}

void min_heap::earn_points(int id, int points){

    outFS << "earnPoints <" << id << "> <" << points << ">" << endl;

    if(handler[id] == -1 || id > capacity){
        outFS << "Contestant <" << id << "> is not in the extended heap." << endl;
    }
    else{
    
        arr[handler[id]].add_points(points);
        min_heapify(handler[id]);
        update_handler();

        outFS << "Contestant <" << id << ">'s score increased by <" << points << "> to <" << arr[handler[id]].get_points() << ">." << endl;
    }
    return;
}

void min_heap::lose_points(int id, int points){

    outFS << "losePoints <" << id << "> <" << points << ">" << endl;

    if(handler[id] == -1 || id > capacity){
        outFS << "Contestant <" << id << "> is not in the extended heap." << endl;
    }
    else{

        arr[handler[id]].lose_points(points);
        for(int i = handler[id]; i < size; i++){
            min_heapify_up(i);
        }
        update_handler();

        outFS << "Contestant <" << id << ">'s score decreased by <" << points << "> to <" << arr[handler[id]].get_points() << ">." << endl;
    }
    return;
}

void min_heap::show_contestants(){

    outFS << "showContestants" << endl;

    for(int i = 1; i < size; i++){
        outFS << "Contestant <" << arr[i].get_name() << "> in extended heap location <" << handler[arr[i].get_name()] << "> with score <" << arr[i].get_points() << ">." << endl;
    }
    return;
}

void min_heap::show_handles(){

    outFS << "showHandles" << endl;

    for(int i = 1; i < capacity; i++){
        if(handler[i] == -1){
            outFS << "There is no contestant <" << i << "> in the extended heap: handle[<" << i << ">] = -1." << endl;
        }
        else{
            outFS << "Contestant <" << i << "> stored in extended heap location <" << handler[i] << ">." << endl;
        }
    }
    return;
}

void min_heap::eliminate_weakest(){

    outFS << "eliminateWeakest" << endl;

    if(size == 1){
        outFS << "No contestant can be eliminated because the heap is empty." << endl;
    }
    else{
        contestant c = arr[1];
        handler[c.get_name()] = -1;
        arr[1] = arr[size-1];
        contestant fake;
        arr[size-1] = fake;
        size--;
        min_heapify(1);
        outFS << "Contestant <" << c.get_name() << "> with current lowest score <" << c.get_points() << "> eliminated." << endl;
        update_handler();
    }
   
    return;
}

void min_heap::crown_winner(){

    outFS << "crownWinner" << endl;

    int i = size;
    while(i > 3){
        if(size == 1){
            break;
        }
        else{
            if(arr[2].get_name() == 0){
                break;
            }
            contestant c = arr[1];
            handler[c.get_name()] = -1;
            arr[1] = arr[size-1];
            contestant fake;
            arr[size-1] = fake;
            size--;
            min_heapify(1);
            update_handler();
 
        }
    }
    outFS << "Contestant <" << arr[1].get_name() << "> wins with score <" << arr[1].get_points() << ">!" << endl;
    return;
}

void min_heap::show_location(int id){

    outFS << "showLocation <" << id << ">" << endl;

    if(handler[id] == -1 || id > capacity){
        outFS << "Contestant <" << id << "> is not in the extended heap:: handler[<" << id << ">] = -1." << endl;
    }
    else{
        outFS << "Contestant <" << id << "> is in the extended heap at location <" << handler[id] << ">." << endl;
    }
    return;

}

void min_heap::print(){
    for(int i = 1; i < size; i++){
        outFS << "Contestant " << arr[i].get_name() << " in extended heap location " << handler[arr[i].get_name()] << " with score " << arr[i].get_points() << "." << endl;
    }
}