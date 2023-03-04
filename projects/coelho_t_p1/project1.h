#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "problem.h"

using namespace std;

string price_list_file;
string market_price_file;

vector<card> card_list;
vector<problem*> problem_list;

ofstream outFS;


