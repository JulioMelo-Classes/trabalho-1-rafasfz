#ifndef KENOBET_H
#define KENOBET_H

#include <iostream>
#include <vector>
#include <cstdlib>

namespace kenobet {

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
      {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
  };

  void show_hits(int spots_size) {
      std::cout << "        ----------+-----------" << std::endl;
    std::cout << "        Hits      | Retorno" << std::endl;

    for(int i = 0; i <= spots_size; i++) {
        if(i > 9)
            std::cout << "        " << i <<"        | " << hits[spots_size - 1][i] <<std::endl;
        else
            std::cout << "         " << i <<"        | " << hits[spots_size - 1][i] <<std::endl;
    }
  }

  using number_type = unsigned short int; //<! data type for a keno hit.
  using cash_type = float; //<! Defines the wage type in this application.
  using set_of_numbers_type = std::vector< number_type >;

  class KenoBet {
      public:
          //! Creates an empty Keno bet.
          KenoBet( ) : m_wage(0)
          { /* empty */ };

          /*! Adds a number to the spots only if the number is not already there.
              @param spot_ The number we wish to include in the bet.
              @return T if number chosen is successfully inserted; F otherwise. */
          bool add_number( number_type spot_ ) {
              for(number_type i : this->m_spots) {
                  if(i == spot_)
                    return false;
              }

              this->m_spots.push_back(spot_);

              return true;
          }

          /*! Sets the amount of money the player is betting.
              @param wage_ The wage.
              @return True if we have a wage above zero; false otherwise. */
          bool set_wage( cash_type wage_ ) {
              if(wage_ < 0) 
                return false;
              
              this->m_wage = wage_;

              return true;
          }

          //! Resets a bet to an empty state.
          void reset( void ) {
              this->m_wage = 0;
              this->m_spots.clear();
          }

          /*! Retrieves the player's wage on this bet.
              @return The wage value. */
          cash_type get_wage( void ) {
              return this->m_wage;
          }

          /*! Returns to the current number of spots in the player's bet.
              @return Number of spots present in the bet. */
          size_t size( void ) {
              return this->m_spots.size();
          }

          /*! Determine how many spots match the hits passed as argument.
              @param hits_ List of hits randomly chosen by the computer.
              @return An vector with the list of hits. */
          set_of_numbers_type
          get_hits( const set_of_numbers_type & hits_ ) {
              set_of_numbers_type hits_matched;

              for(number_type i : hits_) {
                  for(number_type j : this->m_spots) {
                      if(i == j)
                        hits_matched.push_back(i);
                  }
              }

              return hits_matched;
          }

          /*! Return a vector< spot_type > with the spots the player has picked so far.
              @return The vector< spot_type > with the player's spots picked so far. */
          set_of_numbers_type get_spots( void ) {
              return this->m_spots;
          };

          set_of_numbers_type get_random_hits() {
              set_of_numbers_type hits;

              for(int i = 0; i < 15; i++) {
                  int random_number;
                  do {
                    random_number = (rand()%80)+1;
                  } while(search(hits, random_number));
                  hits.push_back(random_number);
              }

              return hits;
          }

          bool search(set_of_numbers_type list, number_type element) {
              for(auto num : list) {
                  if(num == element) {
                      return true;
                  }
              }

              return false;
          }

      private:
          set_of_numbers_type m_spots;  //<! The player's bet.
          cash_type m_wage;             //<! The player's wage
  };
}

#endif