#include "utils/Utils.hpp"

using namespace std;; 

vector<string> split(const string& text, const string& delimiter) {
    vector<string> res;
    size_t start = 0, end = 0;
    while ((end = text.find(delimiter, start)) != string::npos) {
        res.push_back(text.substr(start, end - start));
        start = end + delimiter.length();
    }
    res.push_back(text.substr(start));
    return res;
}

bool is_digit(int c){
    return (c >= '0' && c <= '9');
}

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