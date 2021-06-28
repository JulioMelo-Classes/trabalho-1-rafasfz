#include <iostream>
#include "../include/GetData.h"

using namespace get_data;

int main(int argc, char *argv[]) {
  
  std::string file_name = argv[1];

  bool input_is_valid = validate_input(file_name);

  if(!input_is_valid) {
    std::cout << "Entrada inválida" << std::endl;
    std::cout << "Verifique se sua entrada satisfaz as seguintes regras:" << std::endl;
    std::cout << "1- Repetição de números apostados" << std::endl;
    std::cout << "2- Quantidade de números apostados superior a 15" << std::endl;
    std::cout << "3- Presença de caracteres que não sejam números" << std::endl;
    std::cout << "4- Formatação diferente da proposta" << std::endl;
    std::cout << "5- Arquivo informado inexistente" << std::endl;

    return 1;
  }
  

  return 0;
}