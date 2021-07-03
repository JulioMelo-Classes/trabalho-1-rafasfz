/**
 * @file KenoBet.h
 * @details Contém a classe KenoBet, funções para saber os hits e a tabela de hits.
 */

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
    {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}}; //<! Tabela com os fatores multiplicativos do dinheiro apostado baseado na quantidade de números apostados e números acerados

/*! Printa uma a tabela de hits de acordo com o tamanho dos spots
    @param spots_size o tamanho do número de spots. */
void show_hits(int spots_size);

using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float;                //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector<number_type>;

//!  Classe para a aposta
class KenoBet
{
public:
    //! Creates an empty Keno bet.
    KenoBet() : m_wage(0){/* empty */};

    /*! Adiciona um número ao spot se o número ainda não estiver incluido.
    @param spot_ o número que sera incluido ao spot.
    @return T se o número conseguiu ser inserio, caso o contrário F. */
    bool add_number(number_type spot_);

    /*! Seta o quanto o jogador irá apostar nessa rodada.
    @param wage_ A quantidade do dinheiro que sera apostada.
    @return T se a quantidade for maior que zero, caso o contrário F. */
    bool set_wage(cash_type wage_);

    //! Resets a bet to an empty state.
    void reset(void);

    /*! Retorna a aposta do jogador
    @return O valor da aposta. */
    cash_type get_wage(void);

    /*! Retorna a quanitdade de número que tem no spot atual.
    @return Número de spot atual na aposta. */
    size_t size(void);

    /*! Determina quantos números do spots são o mesmo dos hits passados como argumentos.
    @param hits_ Uma lista de 15 números aletórios diferentes.
    @return Retorna um vetor com os números que combinaram. */
    set_of_numbers_type
    get_hits(const set_of_numbers_type &hits_);

    /*! Retorna um vetor< spot_type > com os spots que o jogador escolheu.
    @return O vetor< spot_type >  com os spots que o jogador escolheu. */
    set_of_numbers_type get_spots(void);

    /*! Retorna um vetor< spot_type > com 15 números aleatórios.
    @return O vetor< spot_type >  com 15 números aleatórios. */
    set_of_numbers_type get_random_hits();

    /*! Verifica se um número está dentro de uma lista
    @param list_ lista que será verificada
    @param element elemento que será verificado se esta dentro da lista
    @return T caso o elemento esteja na lista, F caso o contrario. */
    bool search(set_of_numbers_type list, number_type element);

    /*! Retorna o dinheiro total ganho em todas as apostas
    @return O número em dinheiro total ganho nas apostas */
    cash_type get_total_money();

private:
    set_of_numbers_type m_spots; //<! Os números da aposta atual
    cash_type m_wage;            //<! O dinheiro da aposta atual
    cash_type total_money = 0;   //<! O dinheiro ganhado de todas as apostas somados
};

#endif