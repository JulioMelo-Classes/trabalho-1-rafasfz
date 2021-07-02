#ifndef GRAAL_H
#define GRAAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

void invalid_input();

double get_ic(std::string file_name);

unsigned int get_nr(std::string file_name);

std::vector<int> get_spots(std::string file_name);

bool validate_input(std::string file_name);

#endif