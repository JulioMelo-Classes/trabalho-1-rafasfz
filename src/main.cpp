#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/GetData.h"
#include "../include/KenoBet.h"

int main(int argc, char *argv[]) {
  srand(time(0));
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
  KenoBet bet;

  std::cout << ">>> Aposta lida com sucesso!" << std::endl;
  std::cout << "    Você apostará um total de $" << ic << " créditos." << std::endl;
  std::cout << "    Jogará um total de " << nr << " rodadas, apostando $" << ic/nr << " créditos por rodada" << std::endl;
  std::cout << "    Sua aposta tem "<< spots.size() <<" números, eles são: [ ";
  for(int spot : spots) 
    std::cout << spot << " ";
  std::cout << "]" << std::endl;

  show_hits(spots.size());

  for(int i = 0; i < nr; i++) {
    bet.set_wage(ic/nr);
    for(auto spot : spots) {
      bet.add_number(spot);
    }
    std::vector<unsigned short int> random_hits = bet.get_random_hits();
    std::vector<unsigned short int> matched_hits = bet.get_hits(random_hits);
    
    std::cout << "        ------------------------------------------------------------" << std::endl;
    std::cout << "        Esta é a rodada # "<< i + 1 << " de " << nr << ", sua aposta é $" << bet.get_wage() << ". Boa sorte!" << std::endl;
    std::cout << "        Os números sorteados são: [ ";
    for(auto num : random_hits) 
      std::cout << num << " ";
    std::cout << "]" << std::endl << std::endl;
    std::cout << "        Você acertou os números [ ";
    for(auto num : matched_hits) {
      std::cout << num << " ";
    }
    double moneyInThisBet = bet.get_wage() * hits[spots.size() - 1][matched_hits.size()];
    std::cout << "], um total de " << matched_hits.size() << " hits de " << spots.size() << std::endl;
    std::cout << "        Sua taxa de retorno é " << hits[spots.size() - 1][matched_hits.size()] << ", assim você sai com: $" << moneyInThisBet << std::endl;
    std::cout << "        Você possui um total de: $" << bet.get_total_money() << " créditos." << std::endl;
    bet.reset();
  }

  std::cout << ">>> Fim das rodadas!" << std::endl;
  std::cout << "--------------------------------------------------------------------" << std::endl << std::endl;

  std::cout << ">>> Você gastou um total de $" << ic << " créditos" << std::endl;
  
  if(bet.get_total_money() > ic) {
    std::cout << ">>> Hooray! Você ganhou $" << bet.get_total_money() - ic << " créditos" << std::endl;
  }
  else {
    std::cout << ">>> Poxa! Você perdeu $" << ic - bet.get_total_money() << " créditos" << std::endl;
  }
  std::cout << ">>> Você está saindo do jogo com um total de $" << bet.get_total_money() << " créditos." << std::endl;


  return 0;
}