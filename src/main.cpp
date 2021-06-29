#include <iostream>
#include "../include/GetData.h"

using namespace get_data;

int main(int argc, char *argv[]) {
  
  std::string file_name = argv[1];

  std::cout << ">>> Lendo arquivo de apostas [" << file_name << "], por favor aguarde.." << std::endl;

  std::cout << "--------------------------------------------------------------------" << std::endl;

  bool input_is_valid = validate_input(file_name);

  if(!input_is_valid) {
    invalid_input();

    return 1;
  }
  

  return 0;
}