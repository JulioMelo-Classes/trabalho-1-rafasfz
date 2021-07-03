/**
 * @file GetData.cpp
 * @details Implmentando funcções do header GetData.h
 */


#include "../include/GetData.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

bool verify_string(std::string toVerify, std::string vaildChars) {
  for (auto l1 : toVerify) {
    bool valid = false;
    for (auto l2 : vaildChars) {
      if(l1 == l2)
        valid = true;
    }
    if(!valid)
      return false;
  }

  return true;
}

bool verify_inputs(std::string file_name) {
  std::ifstream input_file(file_name);
  std::string line;

  std::getline(input_file, line);

  if(!verify_string(line, "0123456789. "))
    return false;

  std::getline(input_file, line);
  if(!verify_string(line, "0123456789. "))
    return false;

  std::getline(input_file, line);
  if(!verify_string(line, "0123456789. "))
    return false;

  return true;
}

void invalid_input()
{
  std::cout << "Entrada inválida" << std::endl;
  std::cout << "Verifique se sua entrada satisfaz as seguintes regras:" << std::endl;
  std::cout << "1- Repetição de números apostados" << std::endl;
  std::cout << "2- Quantidade de números apostados superior a 15" << std::endl;
  std::cout << "3- Presença de caracteres que não sejam números" << std::endl;
  std::cout << "4- Formatação diferente da proposta" << std::endl;
  std::cout << "5- Arquivo informado inexistente" << std::endl;
}

double get_ic(std::string file_name)
{
  std::ifstream input_file(file_name);
  std::string line;

  std::getline(input_file, line);
  double ic = std::stod(line);

  return ic;
}

unsigned int get_nr(std::string file_name)
{
  std::ifstream input_file(file_name);
  std::string line;

  std::getline(input_file, line);
  std::getline(input_file, line);
  unsigned int nr = std::stoi(line);

  return nr;
}

std::vector<int> get_spots(std::string file_name)
{
  std::ifstream input_file(file_name);
  std::string line;

  std::getline(input_file, line);
  std::getline(input_file, line);
  std::getline(input_file, line);
  std::vector<int> spots;

  std::stringstream iss(line);

  int number;
  while (iss >> number)
    spots.push_back(number);

  return spots;
}

bool validate_input(std::string file_name)
{

  std::ifstream input_file(file_name);

  if (!input_file)
  {
    return false;
  }

  double ic = get_ic(file_name);
  unsigned int nr = get_nr(file_name);
  std::vector<int> spots = get_spots(file_name);

  if (spots.size() > 15)
  {
    return false;
  }

  for (int num : spots)
  {
    int finded = 0;
    for (int num2 : spots)
    {
      if (num == num2)
        finded++;
    }

    if (finded > 1)
      return false;
  }

  if(!verify_inputs(file_name))
    return false;

  return true;
}