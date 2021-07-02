#ifndef KENOBET_H
#define KENOBET_H

#include <iostream>
#include <vector>
#include <cstdlib>

const std::vector<std::vector<float>> hits = {
    {0, 3},
    {0, 1, 9},
    {0, 1, 2, 16},
    {0, 0.5, 2, 6, 12},
    {0, 0.5, 1, 3, 15, 50},
    {0, 0.5, 1, 2, 3, 30, 75},
    {0, 0.5, 0.5, 1, 6, 12, 36, 100},
    {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
    {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
    {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
    {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
    {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
    {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
    {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
    {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};

void show_hits(int spots_size);

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float;                //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector<number_type>;

class KenoBet
{
public:
    //! Creates an empty Keno bet.
    KenoBet() : m_wage(0){/* empty */};

    /*! Adds a number to the spots only if the number is not already there.
              @param spot_ The number we wish to include in the bet.
              @return T if number chosen is successfully inserted; F otherwise. */
    bool add_number(number_type spot_);

    /*! Sets the amount of money the player is betting.
              @param wage_ The wage.
              @return True if we have a wage above zero; false otherwise. */
    bool set_wage(cash_type wage_);

    //! Resets a bet to an empty state.
    void reset(void);

    /*! Retrieves the player's wage on this bet.
              @return The wage value. */
    cash_type get_wage(void);

    /*! Returns to the current number of spots in the player's bet.
              @return Number of spots present in the bet. */
    size_t size(void);

    /*! Determine how many spots match the hits passed as argument.
              @param hits_ List of hits randomly chosen by the computer.
              @return An vector with the list of hits. */
    set_of_numbers_type
    get_hits(const set_of_numbers_type &hits_);

    /*! Return a vector< spot_type > with the spots the player has picked so far.
              @return The vector< spot_type > with the player's spots picked so far. */
    set_of_numbers_type get_spots(void);

    set_of_numbers_type get_random_hits();

    bool search(set_of_numbers_type list, number_type element);

    cash_type get_total_money();

private:
    set_of_numbers_type m_spots; //<! The player's bet.
    cash_type m_wage;            //<! The player's wage
    cash_type total_money = 0;
};

#endif