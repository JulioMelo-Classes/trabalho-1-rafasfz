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

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float;                //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector<number_type>;

/*! Adds a number to the spots only if the number is not already there.
              @param spot_ The number we wish to include in the bet.
              @return T if number chosen is successfully inserted; F otherwise. */
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

/*! Sets the amount of money the player is betting.
              @param wage_ The wage.
              @return True if we have a wage above zero; false otherwise. */
bool KenoBet::set_wage(cash_type wage_)
{
  if (wage_ < 0)
    return false;

  this->m_wage = wage_;

  return true;
}

//! Resets a bet to an empty state.
void KenoBet::reset(void)
{
  this->m_wage = 0;
  this->m_spots.clear();
}

/*! Retrieves the player's wage on this bet.
              @return The wage value. */
cash_type KenoBet::get_wage(void)
{
  return this->m_wage;
}

/*! Returns to the current number of spots in the player's bet.
              @return Number of spots present in the bet. */
size_t KenoBet::size(void)
{
  return this->m_spots.size();
}

/*! Determine how many spots match the hits passed as argument.
              @param hits_ List of hits randomly chosen by the computer.
              @return An vector with the list of hits. */
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

/*! Return a vector< spot_type > with the spots the player has picked so far.
              @return The vector< spot_type > with the player's spots picked so far. */
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

set_of_numbers_type m_spots; //<! The player's bet.
cash_type m_wage;            //<! The player's wage
cash_type total_money = 0;