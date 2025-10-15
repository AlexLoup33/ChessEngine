#include <iostream>
#include <string>
#include <vector>


#pragma once

/**
 * @brief Split a string into a vector of strings, using a delimiter
 * @param text : the string needed to be split
 * @param delimiter : the delimiter used to split the string
 * @return A vector of strings, result of the split
 */
std::vector<std::string> split(const std::string& text,const std::string& delimiter);

/**
 * @brief Return if the char given is a digit char
 * @param c : the char needed to be compared
 * @return True or False, depend of the value of c
 */
bool is_digit(int c);

/**
 * @brief Return the int pos from string chess position 
 * @param case : the string of the case
 * @return int : the pos between 0 and 63
*/
int StringPositionToInt(const char* c);

/**
 * @brief Dislay the value of a vector as an list
 * @param v : Vector to display
 * @return void
*/
void displayStringVector(std::vector<std::string> v);