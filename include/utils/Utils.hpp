#include <SDL2/SDL_ttf.h>

#include <filesystem>
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
 * @brief Loading properly a font
 * @param path: the path of the font file
 * @param size: the size of the vector path
 * @return TTF_Font* : pointer to a loaded TTF_Font element
 */
TTF_Font* loadFontSafe(const std::vector<std::string>& paths, int size);

//TODO: Add Json Parser and write
