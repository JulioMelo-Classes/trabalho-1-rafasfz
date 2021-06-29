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

  double ic = get_ic(file_name);
  unsigned int nr = get_nr(file_name);
  std::vector<int> spots = get_spots(file_name);

  std::cout << ">>> Aposta lida com sucesso!" << std::endl;
  std::cout << "    Você apostará um total de $" << ic << " créditos." << std::endl;
  std::cout << "    Jogará um total de " << nr << " rodadas, apostando $" << ic/nr << " créditos pro rodada" << std::endl;
  std::cout << "    Sua aposta de "<< spots.size() <<" números, eles são: [ ";
  for(int spot : spots) 
    std::cout << spot << " ";
  std::cout << "]" << std::endl;

  for(int i = 0; i < nr; i++) {

  }
  

  return 0;
}