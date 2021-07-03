/**
 * @file GetData.h
 * @details Classe parar pegar e validar os valores dos inputs.
 */

#ifndef GRAAL_H
#define GRAAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>

/*! Verifica se se os caracteres de uma string estão contidas em outra string.
 @param toVerify string que sera verificada.
 @param vaildChars string que contém os caracteres que deverão estar presentes na outra string.
 @return T se todos os carcteres de toVerify estiver em validChars, caso contrario F. */
bool verify_string(std::string toVerify, std::string vaildChars);

//! Imprime as menssagens de input inválidos
void invalid_input();

/*! Pegar o valor ic
 @param file_name nome do arquivo de onde será pegado o ic.
 @return o valor do ic. */
double get_ic(std::string file_name);

/*! Pegar o valor nr
 @param file_name nome do arquivo de onde será pegado o nr.
 @return o valor do nr. */
unsigned int get_nr(std::string file_name);

/*! Pegar os spots
 @param file_name nome do arquivo de onde será pegado os spots.
 @return O vetor com os spots. */
std::vector<int> get_spots(std::string file_name);

/*! Verifica se os valores dos inputs estão seguindo as regras implementadas
 @param file_name nome do arquivo de onde será pegado os inputs.
 @return T se todos os requisitos de validação forem seguidos, caso o contrário F. */
bool validate_input(std::string file_name);

#endif