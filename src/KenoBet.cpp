/**
 * @file KenoBet.cpp
 * @details Implmentando metodos e funções do header KenoBet.h
 */

#include "../include/KenoBet.h"

#include <iostream>
#include <vector>
#include <cstdlib>

void show_hits(int spots_size)
{
  std::cout << "        ----------+-----------" << std::endl;
  std::cout << "        Hits      | Retorno" << std::endl;

  for (int i = 0; i <= spots_size; i++)
  {
    if (i > 9)
      std::cout << "        " << i << "        | " << hits[spots_size - 1][i] << std::endl;
    else
      std::cout << "         " << i << "        | " << hits[spots_size - 1][i] << std::endl;
  }
}

using number_type = unsigned short int;
using cash_type = float;               
using set_of_numbers_type = std::vector<number_type>;

bool KenoBet::add_number(number_type spot_)
{
  for (number_type i : this->m_spots)
  {
    if (i == spot_)
      return false;
  }

  this->m_spots.push_back(spot_);

  return true;
}

bool KenoBet::set_wage(cash_type wage_)
{
  if (wage_ < 0)
    return false;

  this->m_wage = wage_;

  return true;
}

void KenoBet::reset(void)
{
  this->m_wage = 0;
  this->m_spots.clear();
}

cash_type KenoBet::get_wage(void)
{
  return this->m_wage;
}

size_t KenoBet::size(void)
{
  return this->m_spots.size();
}

set_of_numbers_type
KenoBet::get_hits(const set_of_numbers_type &hits_)
{
  set_of_numbers_type hits_matched;

  for (number_type i : hits_)
  {
    for (number_type j : this->m_spots)
    {
      if (i == j)
        hits_matched.push_back(i);
    }
  }

  this->total_money += hits[this->m_spots.size() - 1][hits_matched.size()] * this->m_wage;
  return hits_matched;
}

set_of_numbers_type KenoBet::get_spots(void)
{
  return this->m_spots;
};

set_of_numbers_type KenoBet::get_random_hits()
{
  set_of_numbers_type hits;

  for (int i = 0; i < 15; i++)
  {
    int random_number;
    do
    {
      random_number = (rand() % 80) + 1;
    } while (search(hits, random_number));
    hits.push_back(random_number);
  }

  return hits;
}

bool KenoBet::search(set_of_numbers_type list, number_type element)
{
  for (auto num : list)
  {
    if (num == element)
    {
      return true;
    }
  }

  return false;
}

cash_type KenoBet::get_total_money()
{
  return this->total_money;
}

set_of_numbers_type m_spots;
cash_type m_wage;
cash_type total_money = 0;