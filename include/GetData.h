#ifndef GRAAL_H
#define GRAAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

namespace get_data {

  double get_ic(std::string file_name) {
    std::ifstream input_file(file_name);
    std::string line;

    std::getline(input_file, line);
    double ic = std::stod(line);

    return ic;
  }

  unsigned int get_nr(std::string file_name) {
    std::ifstream input_file(file_name);
    std::string line;

    std::getline(input_file, line);
    std::getline(input_file, line);
    unsigned int nr = std::stoi(line);

    return nr;
  }

  std::vector<int> get_spots(std::string file_name) {
    std::ifstream input_file(file_name);
    std::string line;

    std::getline(input_file, line);
    std::getline(input_file, line);
    std::getline(input_file, line);
    std::vector<int> spots;

    std::stringstream iss(line);

    int number;
    while(iss >> number)
      spots.push_back(number);

    return spots;
  }

  bool validate_input(std::string file_name) {

    std::ifstream input_file(file_name);

    if(!input_file) {
      return false;
    }

    double ic = get_ic(file_name);
    unsigned int nr = get_nr(file_name);
    std::vector<int> spots = get_spots(file_name);

    if(spots.size() > 15) {
      return false;
    }

    for(int num : spots) {
      int finded = 0;
      for(int num2 : spots) {
        if(num == num2)
          finded++;

      }

      if(finded > 1)
        return false;
    }

    return true;
  }

}

#endif