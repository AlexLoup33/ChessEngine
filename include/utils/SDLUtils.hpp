#include <SDL2/SDL_ttf.h>
#include <filesystem>

#include <vector>
#include <iostream>

/**
 * @brief Loading properly a font
 * @param path: the path of the font file
 * @param size: the size of the vector path
 * @return TTF_Font* : pointer to a loaded TTF_Font element
 */
TTF_Font* loadFontSafe(const std::vector<std::string>& paths, int size);
