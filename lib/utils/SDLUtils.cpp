#include "utils/SDLUtils.hpp"


using namespace std;;

TTF_Font *loadFontSafe(const vector<string> &paths, int size){
    for (const auto& path: paths){
        if (filesystem::exists(path)){
            TTF_Font* font = TTF_OpenFont(path.c_str(), size);
            if (font){
                cout << "Loaded font: " << path << endl;
                return font;
            }
        }
    }
    cerr << "Failed to load any font. TTF error: " << TTF_GetError() << endl; 
    throw runtime_error("Failed to load font");
}