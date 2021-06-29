#include <iostream>
#include "../include/GetData.h"
#include "../include/KenoBet.h"

using namespace get_data;
using namespace kenobet;

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
  std::cout << "    Jogará um total de " << nr << " rodadas, apostando $" << ic/nr << " créditos por rodada" << std::endl;
  std::cout << "    Sua aposta tem "<< spots.size() <<" números, eles são: [ ";
  for(int spot : spots) 
    std::cout << spot << " ";
  std::cout << "]" << std::endl;

  std::cout << "        ----------+-----------" << std::endl;
  std::cout << "        Hits      | Retorno" << std::endl;

  for(int i = 0; i <= spots.size(); i++) {
    if(i > 9) {
      std::cout << "        " << i <<"        | " << hits[spots.size() - 1][i] <<std::endl;
    } else {
      std::cout << "         " << i <<"        | " << hits[spots.size() - 1][i] <<std::endl;
    }
  }
  

  return 0;
}